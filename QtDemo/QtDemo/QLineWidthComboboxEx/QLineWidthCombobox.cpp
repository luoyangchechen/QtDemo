#include "QLineWidthCombobox.h"
#include<QHBoxLayout>
#include<QPainter>
#include<QPaintEvent>
#include<QPoint>
#include<QLine>
QPenWidth::QPenWidth(QWidget  *parent)
	: QLabel(parent)
	, m_drawType(0)
	, m_size(1)
{
}

QPenWidth::~QPenWidth()
{
}

void QPenWidth::SetDrawParameters(int drawType, int isize)
{
	m_drawType = drawType;
	m_size = isize;
}

void QPenWidth::paintEvent(QPaintEvent *)
{
	QSize size = this->size();
	QPainter painter(this);
	QPen pen;
	pen.setColor(Qt::black);
	pen.setWidth(m_size);
	painter.setPen(pen);
	if (m_drawType == 0)
		painter.drawPoint(QPoint(size.width() / 2, size.height() / 2));
	else
	{

		QPoint p1(0, size.height() / 2);
		QPoint p2(size.width(), size.height() / 2);
		QLine line(p1, p2);
		painter.drawLine(line);
	}

}

QPenWidget::QPenWidget(QWidget *parent /*= Q_NULLPTR*/)
	:QLineEdit(parent)
	, m_index(0)
	, m_type(0)
{
	m_pLabel = new QLabel();
	m_pCssLabel = new QPenWidth();

	m_pLabel->setFixedSize(12, 12);

	QHBoxLayout* layout = new QHBoxLayout();
	layout->addWidget(m_pLabel);
	layout->addWidget(m_pCssLabel);
	layout->setContentsMargins(5, 0, 0, 2);
	setLayout(layout);
	setReadOnly(true);

	setStyleSheet("QLineEdit{border: none;}QLineEdit:hover{background-color:rgb(0,125,255);}");

}

QPenWidget::~QPenWidget()
{

}

void QPenWidget::updatePen(const int& index, const int& type)
{
	m_index = index;
	m_type = type;

	QString strText = QString("%1 )").arg(QString::number(m_index));
	m_pLabel->setText(strText);
	m_pCssLabel->SetDrawParameters(type, index);

}

void QPenWidget::mousePressEvent(QMouseEvent *event)
{
	emit click(m_index);
}

QLineWidthCombobox::QLineWidthCombobox(QWidget *parent /*= Q_NULLPTR*/)
	:QComboBox(parent)
	, m_drawType(1)
{
	m_pPenEdit = new QPenWidget();
	m_pListWidget = new QListWidget();
	m_pPenEdit->setStyleSheet("");
	setContextMenuPolicy(Qt::NoContextMenu);//禁用菜单
	m_pListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//禁用垂直滚动条
	m_pListWidget->setStyleSheet("QListWidget::Item:hover{background-color:rgb(0,125,255);}");
	setLineEdit(m_pPenEdit);
	setModel(m_pListWidget->model());
	setView(m_pListWidget);
}

QLineWidthCombobox::~QLineWidthCombobox()
{

}

void QLineWidthCombobox::SetType(int drawType)
{
	m_drawType = drawType;
}

int QLineWidthCombobox::GetCurrentIndex()
{
	return m_index;
}

void QLineWidthCombobox::SetCurrentIndex(int index)
{
	m_index = index;
	m_pPenEdit->updatePen(index, m_drawType);
}

void QLineWidthCombobox::SetList(QList<int>&list)
{
	m_list = list;
	m_pListWidget->clear();
	int icount = m_list.count();
	for (int i = 0; i < icount; i++)
		appendItem(m_list[i]);
}

QList<int> QLineWidthCombobox::GetList()
{
	return m_list;
}

void QLineWidthCombobox::onClickPenWidget(const int& index)
{
	m_index = index;
	m_pPenEdit->updatePen(index, m_drawType);
	hidePopup();
	emit SelectedItemChanged(m_index);
}

void QLineWidthCombobox::appendItem(const int& index)
{
	QPenWidget* pWid = new QPenWidget(this);
	pWid->updatePen(index, m_drawType);
	connect(pWid, SIGNAL(click(const int&)), this, SLOT(onClickPenWidget(const int&)));
	QListWidgetItem* pItem = new QListWidgetItem(m_pListWidget);

	m_pListWidget->addItem(pItem);
	m_pListWidget->setItemWidget(pItem, pWid);
}
