#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QLineWidthComboboxEx.h"

class QLineWidthComboboxEx : public QMainWindow
{
    Q_OBJECT

public:
    QLineWidthComboboxEx(QWidget *parent = Q_NULLPTR);

private:
    Ui::QLineWidthComboboxExClass ui;
};
