#include "ErrorBox.h"

ErrorBox::ErrorBox(
	const QString& title,
	const QString& msg,
	const QSize& sz,
	QDialog* parent)
	: MsgBox(title, msg, ":/res/img/error_box_lbl.png", "#E55353", sz, parent)
{
}

ErrorBox::~ErrorBox()
{
}
