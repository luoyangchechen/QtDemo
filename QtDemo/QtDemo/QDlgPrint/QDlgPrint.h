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
	void doPrint();//打印
	void doPrintPreview();//打印预览
	void createPDF();//生成pdf

	void printPreview(QPrinter* p);

private:
	Ui::QDlgPrintClass ui;
};
