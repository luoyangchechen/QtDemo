#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QDlgPrint.h"

class QPrinter;
class QDlgPrint : public QMainWindow
{
	Q_OBJECT

public:
	QDlgPrint(QWidget *parent = Q_NULLPTR);

private slots:
	void doPrint();//��ӡ
	void doPrintPreview();//��ӡԤ��
	void createPDF();//����pdf

	void printPreview(QPrinter* p);

private:
	Ui::QDlgPrintClass ui;
};
