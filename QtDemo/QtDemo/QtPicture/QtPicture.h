#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtPicture.h"

//快捷键 Alt+o   .h和.cpp来回切换

class QtPicture : public QWidget
{
	Q_OBJECT

public:
	QtPicture(QWidget *parent = Q_NULLPTR);

protected:
	void paintEvent(QPaintEvent *event);

private:
	Ui::QtPictureClass ui;
};
