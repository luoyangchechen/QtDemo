#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QComboboxEx.h"

class QComboboxEx : public QMainWindow
{
	Q_OBJECT

public:
	QComboboxEx(QWidget *parent = Q_NULLPTR);

private:
	Ui::QComboboxExClass ui;
};
