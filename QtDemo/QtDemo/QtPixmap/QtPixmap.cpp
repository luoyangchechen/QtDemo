#include "QtPixmap.h"
#include <QPainter>

QtPixmap::QtPixmap(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//绘图设备
	QPixmap pixmpa(400,711);
	QPainter p(&pixmpa);
	//填充白色
	p.fillRect(0, 0, 400, 711, QBrush(Qt::white));
	p.drawPixmap(0,0,400,711,QPixmap(":/Image/lufei.jpg"));
	

	//保存图片
	pixmpa.save("./pixmap.png");
}
