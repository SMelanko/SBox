#include "MsgBox.h"

#include <QBoxLayout>
#include <QLabel>
#include <QPropertyAnimation>
#include <QPushButton>

MsgBox::MsgBox(
	const QString& title,
	const QString& msg,
	const QString& lbl,
	const QColor& col,
	const QSize& sz,
	QDialog *parent)
	: QDialog(parent)
	, m_anim(new QPropertyAnimation(this, "windowOpacity"))
	, m_close(new QPushButton(this))
{
	Init(title, msg, lbl);

	setAttribute(Qt::WA_DeleteOnClose);
	setFixedSize(sz);
	setStyleSheet(QString(
		"QDialog { background-color: %1; border: none; }").arg(col.name()));
	setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

	connect(m_anim, &QPropertyAnimation::finished, this, &MsgBox::OnClose);
	connect(m_close, &QPushButton::clicked, this, &MsgBox::OnClose);
}

MsgBox::~MsgBox()
{
}

void MsgBox::Init(const QString& title, const QString& msg, const QString& lbl)
{
	QHBoxLayout* mainLayout(new QHBoxLayout);

	// Close label.
	QLabel* close(new QLabel(this));
	close->setPixmap(QPixmap(lbl));
	mainLayout->addWidget(close);

	// Error message section.
	QLabel* text(new QLabel(this));
	text->setText(QString(
		"<font size=\"5\" color=\"white\">%1<br></font>"
		"<font size=\"3\" color=\"white\">%2</font>")
		.arg(title).arg(msg));
	mainLayout->addWidget(text);
	mainLayout->addStretch(1);

	// Close button section.
	QVBoxLayout* layout(new QVBoxLayout);
	layout->setAlignment(Qt::AlignTop);
	m_close->setCursor(Qt::PointingHandCursor);
	m_close->setIcon(QPixmap(":/res/img/msg_box_close.png"));
	layout->addWidget(m_close);
	mainLayout->addLayout(layout);

	setLayout(mainLayout);
}

void MsgBox::mousePressEvent(QMouseEvent*)
{
	m_anim->stop();
	m_anim->setDuration(100);
	m_anim->setStartValue(1);
	m_anim->setEndValue(0);
	m_anim->start();
	m_anim->pause();
}

void MsgBox::OnClose()
{
	close();

	Q_EMIT Close();
}

void MsgBox::Show()
{
	show();

	m_anim->setDuration(4000);
	m_anim->setStartValue(2);
	m_anim->setEndValue(0);
	m_anim->start();
}
