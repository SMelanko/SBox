#pragma once

#ifndef _SBOX_ERRORBOX_H_
#define _SBOX_ERRORBOX_H_

#include "MsgBox.h"

class ErrorBox : public MsgBox
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	explicit ErrorBox(
		const QString& title,
		const QString& msg,
		const QSize& sz,
		QDialog* parent = Q_NULLPTR);
	//! Destructor.
	~ErrorBox();
};

#endif // _SBOX_INFOBOX_H_
