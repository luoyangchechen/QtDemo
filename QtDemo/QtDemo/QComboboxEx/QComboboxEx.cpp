#include "QComboboxEx.h"

QComboboxEx::QComboboxEx(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.comboBox->appendItem(QColor(0, 0, 0));
	ui.comboBox->appendItem(QColor(0, 0, 255));
	ui.comboBox->appendItem(QColor(255, 255, 255));
	ui.comboBox->appendItem(QColor(255, 0, 0));
	ui.comboBox->appendItem(QColor(255, 255, 0));
	ui.comboBox->appendItem(QColor(255, 0, 255));
	ui.comboBox->appendItem(QColor(0, 255, 255));
	ui.comboBox->appendItem(QColor(0, 255, 0));
}
