#include "QtPixmap.h"
#include <QPainter>

QtPixmap::QtPixmap(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//��ͼ�豸
	QPixmap pixmpa(400,711);
	QPainter p(&pixmpa);
	//����ɫ
	p.fillRect(0, 0, 400, 711, QBrush(Qt::white));
	p.drawPixmap(0,0,400,711,QPixmap(":/Image/lufei.jpg"));
	

	//����ͼƬ
	pixmpa.save("./pixmap.png");
}
