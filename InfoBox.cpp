#include "InfoBox.h"

InfoBox::InfoBox(
	const QString& title,
	const QString& msg,
	const QSize& sz,
	QDialog* parent)
	: MsgBox(title, msg, ":/info_lbl.png", "#008A36", sz, parent)
{
}

InfoBox::~InfoBox()
{
}
