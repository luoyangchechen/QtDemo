#include "QDlgPrint.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QDlgPrint w;
	w.show();
	return a.exec();
}
