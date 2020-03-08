#include "QDlgShapeless.h"
#include <QPainter>
#include <QMouseEvent>

QDlgShapeless::QDlgShapeless(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//去边框 同时保留窗口原有的属性
	setWindowFlags(Qt::FramelessWindowHint |windowFlags());

	//把窗口背景设为透明
	setAttribute(Qt::WA_TranslucentBackground);
}

void QDlgShapeless::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::RightButton)
	{
		//如果是右键关闭
		close();
	}
	else if (event->button() == Qt::LeftButton)
	{
		  move_point = event->globalPos() - this->pos(); //移动的距离
	}
}

void QDlgShapeless::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)//判断按下的事左键
	{
		move(event->globalPos() - move_point);
	}
}

void QDlgShapeless::paintEvent(QPaintEvent *event)
{
	QPainter p(this);

	p.drawPixmap(0, 0, QPixmap(":/Image/122.png"));
}
