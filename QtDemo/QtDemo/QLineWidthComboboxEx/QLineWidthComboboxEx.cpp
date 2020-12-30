#include "QLineWidthComboboxEx.h"
#include "QLineWidthCombobox.h"

QLineWidthComboboxEx::QLineWidthComboboxEx(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	ui.comboBox->appendItem(1);
	ui.comboBox->appendItem(2);
	ui.comboBox->appendItem(3);
	ui.comboBox->appendItem(4);
	ui.comboBox->appendItem(5);
}
