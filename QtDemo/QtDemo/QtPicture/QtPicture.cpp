#include "QtPicture.h"
#include <QPainter>
#include <QPicture>

QtPicture::QtPicture(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QPicture picture;
	QPainter p;
	p.begin(&picture);

	p.drawPixmap(0,0,80,80,QPixmap(":/Image/lufei.jpg"));
	p.drawLine(50, 50, 150, 50);
	p.end();

	picture.save("./picture.png");//二进制文件 
}

void QtPicture::paintEvent(QPaintEvent *event)
{
#if 0
	QPicture pic;
	pic.load("./picture.png");//加载文件

	QPainter p(this);
	p.drawPicture(0, 0, pic);
#endif

	QPainter p(this);
	QPixmap pix;
	pix.load(":/Image/lufei.jpg");
	//QPixmap -- > QImage
	QImage img = pix.toImage();
	p.drawImage(0, 0, img);


	QImage tempImg;
	tempImg.load(":/Image/lufei.jpg");

	//QImage --> QPixmap
	QPixmap temPix = QPixmap::fromImage(tempImg);
	p.drawPixmap(400, 0, temPix);
}
