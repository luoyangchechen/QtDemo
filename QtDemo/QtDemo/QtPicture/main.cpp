#include "QtPicture.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtPicture w;
	w.show();
	return a.exec();
}
