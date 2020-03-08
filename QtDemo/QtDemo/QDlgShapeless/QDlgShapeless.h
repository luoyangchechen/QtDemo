#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QDlgShapeless.h"

class QDlgShapeless : public QMainWindow
{
	Q_OBJECT

public:
	QDlgShapeless(QWidget *parent = Q_NULLPTR);

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);



protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::QDlgShapelessClass ui;

	QPoint move_point; //ÒÆ¶¯µÄ¾àÀë
};
