#pragma once

#include<QComboBox>
#include<QLabel>
#include<QLineEdit>
#include<QListWidget>

class QPenWidth : public QLabel
{
	Q_OBJECT

public:
	QPenWidth(QWidget  *parent = Q_NULLPTR);
	~QPenWidth();

	void SetDrawParameters(int drawType, int isize);
protected:
	void paintEvent(QPaintEvent *) override;
private:
	int m_drawType;//画点，还是画线
	int m_size;//大小
};


class  QPenWidget : public QLineEdit
{
	Q_OBJECT
public:
	QPenWidget(QWidget *parent = Q_NULLPTR);
	~QPenWidget();

	void updatePen(const int& index, const int& type);
protected:
	void mousePressEvent(QMouseEvent *event);

signals:
	void click(const int& index);
private:
	QLabel* m_pLabel;
	QPenWidth* m_pCssLabel;
	int m_index;
	int m_type;
};

class  QLineWidthCombobox :public QComboBox
{
	Q_OBJECT
public:
	QLineWidthCombobox(QWidget *parent = Q_NULLPTR);
	~QLineWidthCombobox();

	void SetType(int drawType);

	int GetCurrentIndex();
	void SetCurrentIndex(int index);

	void SetList(QList<int>&list);
	QList<int> GetList();

private slots:
	void onClickPenWidget(const int& index);

signals:
	void SelectedItemChanged(int);

public:
	void appendItem(const int& index);
private:
	QPenWidget* m_pPenEdit;
	QListWidget* m_pListWidget;
	QList<QColor> m_colorsList;
	int m_drawType;
	int m_index;
	QList<int> m_list;
};
