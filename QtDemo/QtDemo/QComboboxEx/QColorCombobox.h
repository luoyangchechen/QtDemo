#pragma once
#include <QLineEdit>
#include <QCombobox>

class QLabel;
class QListWidget;

class QColorWidget : public QLineEdit
{
Q_OBJECT
public:
	QColorWidget(QWidget *parent = Q_NULLPTR);
	~QColorWidget();

	void updateColor(const QColor& color);

	void mousePressEvent(QMouseEvent *event);

signals:
	void click(const QColor& color);
private:
	QLabel* m_pLabel;
	QLabel* m_pRgbLabel;
	QColor m_color;
};

class QColorCombobox :public QComboBox 
{
	Q_OBJECT
public:
	QColorCombobox(QWidget *parent = Q_NULLPTR);
	~QColorCombobox();

	void appendItem(const QColor& color);

private slots:
	void onClickColorWidget(const QColor& color);
private:
	QColorWidget* m_pLineEdit;
	QListWidget* m_pListWidget;
};

