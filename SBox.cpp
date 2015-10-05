#include "SBox.h"

#include "ErrorBox.h"
#include "InfoBox.h"

#include <QCloseEvent>
#include <QVBoxLayout>
#include <QPushButton>

SBox::SBox(QWidget *parent)
	: QDialog(parent)
	, m_mb(Q_NULLPTR)
{
	Init();
	resize(360, 480);
}

SBox::~SBox()
{
	if (m_mb)
		delete m_mb;
}

void SBox::closeEvent(QCloseEvent* event)
{
	if (m_mb)
		Q_EMIT m_mb->Close();
	event->accept();
}

void SBox::Init()
{
	QVBoxLayout* lay(new QVBoxLayout(this));

	QPushButton* but(new QPushButton(tr("Show msg box"), this));
	but->setStyleSheet(
		"QPushButton {"
			"background-color: #007ee5;"
			"border: 1px solid #0070cc;"
			"border-radius: 3px;"
			"color: white;"
		"}"
		"QPushButton:hover {"
			"background-color: #008cff;"
		"}"
		"QPushButton:pressed {"
			"background-color: #1998ff;"
		"}");
	but->setMinimumHeight(35);
	lay->addWidget(but);

	setLayout(lay);

	connect(but, SIGNAL(clicked()), SLOT(OnShowMsgBox()));
}

void SBox::moveEvent(QMoveEvent* event)
{
	if (m_mb)
		m_mb->move(event->pos());
	event->accept();
}

void SBox::OnShowMsgBox()
{
	OnShow("Title", "Message context");
}

void SBox::OnShow(const QString& title, const QString& msg)
{
	QRect pos(geometry());
	m_mb = new ErrorBox(title, msg, QSize(pos.width(), 75), this);
	m_mb->move(pos.x(), pos.y());
	m_mb->Show();

	connect(m_mb, &MsgBox::Close, [&](){
			delete m_mb;
			m_mb = Q_NULLPTR;
	});
}
