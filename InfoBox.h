#pragma once

#ifndef _SBOX_INFOBOX_H_
#define _SBOX_INFOBOX_H_

#include "MsgBox.h"

class InfoBox : public MsgBox
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	explicit InfoBox(
		const QString& title,
		const QString& msg,
		const QSize& sz,
		QDialog* parent = Q_NULLPTR);
	//! Destructor.
	~InfoBox();
};

#endif // _SBOX_INFOBOX_H_
