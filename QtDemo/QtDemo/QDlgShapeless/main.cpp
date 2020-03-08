#include "QDlgShapeless.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QDlgShapeless w;
	w.show();
	return a.exec();
}
