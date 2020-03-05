#include "QColorCombobox.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QListWidget>

QColorWidget::QColorWidget(QWidget *parent /*= Q_NULLPTR*/)
	:QLineEdit(parent)
	,m_color(255,0,0)
{
	m_pLabel = new QLabel(this);
	m_pRgbLabel = new QLabel(this);

	m_pLabel->setFixedSize(15, 15);

	QHBoxLayout* layout = new QHBoxLayout();
	layout->addWidget(m_pLabel);
	layout->addWidget(m_pRgbLabel);
	layout->setContentsMargins(5, 0, 0, 0);
	setLayout(layout);
	setReadOnly(true);

	//setStyleSheet("border: none");
	//setContextMenuPolicy(Qt::NoContextMenu);//禁用菜单
	//setFocusPolicy(Qt::NoFocus);

	setStyleSheet("QLineEdit{border: none;}QLineEdit:hover{background-color:rgb(0,125,255);}");
}


QColorWidget::~QColorWidget()
{

}

void QColorWidget::updateColor(const QColor& color)
{
	m_color = color;

	QString strstyle = QString("border:1px solid black;background-color:rgb(%1,%2,%3);").arg(QString::number(color.red()), QString::number(color.green()), QString::number(color.blue()));
	QString strText = QString("%1,%2,%3").arg(QString::number(color.red()), QString::number(color.green()), QString::number(color.blue()));
	m_pLabel->setStyleSheet(strstyle);
	m_pRgbLabel->setText(strText);
}

void QColorWidget::mousePressEvent(QMouseEvent *event)
{
	emit click(m_color);
}




QColorCombobox::QColorCombobox(QWidget *parent /*= Q_NULLPTR*/)
	:QComboBox(parent)
{
	m_pLineEdit = new QColorWidget(this);
	m_pListWidget = new QListWidget(this);
	m_pLineEdit->setStyleSheet("");
	setContextMenuPolicy(Qt::NoContextMenu);//禁用菜单
	m_pListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//禁用垂直滚动条
	m_pListWidget->setStyleSheet("QListWidget::Item:hover{background-color:rgb(0,125,255);}");
	setLineEdit(m_pLineEdit);
	setModel(m_pListWidget->model());
	setView(m_pListWidget);

}

QColorCombobox::~QColorCombobox()
{
}

void QColorCombobox::appendItem(const QColor& color)
{
	QColorWidget* pWid = new QColorWidget(this);
	pWid->updateColor(color);
	connect(pWid, SIGNAL(click(const QColor&)),this,SLOT(onClickColorWidget(const QColor&)));
	QListWidgetItem* pItem = new QListWidgetItem(m_pListWidget);
	
	m_pListWidget->addItem(pItem);
	m_pListWidget->setItemWidget(pItem, pWid);

}

void QColorCombobox::onClickColorWidget(const QColor& color)
{
	m_pLineEdit->updateColor(color);
	hidePopup();

	emit currentIndexChanged(m_pListWidget->currentRow());
}
