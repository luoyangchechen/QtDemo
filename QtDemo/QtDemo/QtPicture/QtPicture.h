#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtPicture.h"

//��ݼ� Alt+o   .h��.cpp�����л�

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
