#pragma once

#ifndef _SBOX_MSGBOX_H_
#define _SBOX_MSGBOX_H_

#include <QDialog>

QT_FORWARD_DECLARE_CLASS(QPropertyAnimation)
QT_FORWARD_DECLARE_CLASS(QPushButton)

class MsgBox : public QDialog
{
	Q_OBJECT

	//
	// Public methods.
	//
public:
	//! Constructor.
	explicit MsgBox(
		const QString& title,
		const QString& msg,
		const QString& lbl,
		const QColor& col,
		const QSize& sz,
		QDialog* parent = Q_NULLPTR);
	//! Destructor.
	virtual ~MsgBox();
	//! Shows error box with animation effect.
	void Show();

	//
	// Class's signals.
	//
Q_SIGNALS:
	//! Emits close signal into wizard, where deletes error box.
	void Close();

	//
	// Protected methods.
	//
protected:
	//! Receives mouse press events for the widget.
	void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;

	//
	// Private methods.
	//
private:
	//! Initializes widget's content.
	void Init(const QString& title, const QString& msg, const QString& lbl);

	//
	// Private slots.
	//
private Q_SLOTS:
	//! Closes error box.
	void OnClose();

	//
	// Private data members.
	//
private:
	//! Property for attenuation error box.
	QPropertyAnimation* m_anim;
	//! Close button.
	QPushButton* m_close;
};

#endif // _SBOX_MSGBOX_H_
