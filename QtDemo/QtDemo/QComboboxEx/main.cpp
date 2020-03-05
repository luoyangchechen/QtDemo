#include "QComboboxEx.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QComboboxEx w;
	w.show();
	return a.exec();
}
