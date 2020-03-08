#include "QDlgShapeless.h"
#include <QPainter>
#include <QMouseEvent>

QDlgShapeless::QDlgShapeless(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//ȥ�߿� ͬʱ��������ԭ�е�����
	setWindowFlags(Qt::FramelessWindowHint |windowFlags());

	//�Ѵ��ڱ�����Ϊ͸��
	setAttribute(Qt::WA_TranslucentBackground);
}

void QDlgShapeless::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::RightButton)
	{
		//������Ҽ��ر�
		close();
	}
	else if (event->button() == Qt::LeftButton)
	{
		  move_point = event->globalPos() - this->pos(); //�ƶ��ľ���
	}
}

void QDlgShapeless::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)//�жϰ��µ������
	{
		move(event->globalPos() - move_point);
	}
}

void QDlgShapeless::paintEvent(QPaintEvent *event)
{
	QPainter p(this);

	p.drawPixmap(0, 0, QPixmap(":/Image/122.png"));
}
