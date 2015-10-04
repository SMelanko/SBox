#include "SBox.h"
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	SBox w;
	w.show();

	return a.exec();
}
