#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtPixmap.h"

class QtPixmap : public QMainWindow
{
	Q_OBJECT

public:
	QtPixmap(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtPixmapClass ui;
};
