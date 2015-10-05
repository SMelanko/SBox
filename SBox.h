#pragma once

#ifndef _SBOX_H_
#define _SBOX_H_

#include <QDialog>

class MsgBox;

class SBox : public QDialog
{
	Q_OBJECT

	//
	// Public methods.
	//
public:
	//! Default constructor.
	SBox(QWidget* parent = Q_NULLPTR);
	//! Destructor.
	~SBox();

	//
	// Public slots.
	//
public Q_SLOTS:
	//! Shows message in the top of the widget.
	void OnShow(const QString& title, const QString& msg);

	//
	// Protected methods.
	//
protected:
	//! Receives a window close request.
	void closeEvent(QCloseEvent* event) Q_DECL_OVERRIDE;
	//! Receives widget move events which are passed in the event parameter.
	void moveEvent(QMoveEvent* event) Q_DECL_OVERRIDE;

	//
	// Private methods.
	//
private:
	//! Initializes dialog's content.
	void Init();

	//
	// Private slots.
	//
private slots:
	//! Shows message box.
	void OnShowMsgBox();

	//
	// Private data members.
	//
private:
	//! Message box.
	MsgBox* m_mb;
};

#endif // _SBOX_H_
