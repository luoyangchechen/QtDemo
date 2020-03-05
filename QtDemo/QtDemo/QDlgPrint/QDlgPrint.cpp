#include "QDlgPrint.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QPrintPreviewDialog>
#include <QFileDialog>
#include <QMessageBox>

QDlgPrint::QDlgPrint(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QAction *action_print = new QAction(QStringLiteral("��ӡ"), this);
	QAction *action_printPreview = new QAction(QStringLiteral("��ӡԤ��"), this);
	QAction *action_pdf = new QAction(QStringLiteral("����pdf"), this);

	connect(action_print, SIGNAL(triggered()), this, SLOT(doPrint()));
	connect(action_printPreview, SIGNAL(triggered()), this, SLOT(doPrintPreview()));
	connect(action_pdf, SIGNAL(triggered()), this, SLOT(createPDF()));

	ui.mainToolBar->addAction(action_print);
	ui.mainToolBar->addAction(action_printPreview);
	ui.mainToolBar->addAction(action_pdf);
}

void QDlgPrint::doPrint()
{
	// ������ӡ������
	QPrinter printer;
	QString printerName = printer.printerName();

	if (printerName.size() == 0)
	{
		QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("û���ҵ���ӡ��"));
		return;
	}

	QPrintDialog dlg;

	if (dlg.exec() == QDialog::Accepted)
	{
		QTextDocument doc;
		QFont font = doc.defaultFont();
		font.setPointSize(3);
		doc.setDefaultFont(font);
		//��ӡ�ߴ�
		QSizeF s = QSizeF(printer.logicalDpiX() * (58 / 25.4), printer.logicalDpiY() * (297 / 25.4));
		doc.setPageSize(s);
		printer.setPageSizeMM(s);
		printer.setOutputFormat(QPrinter::NativeFormat);
		doc.print(&printer);
	}
}

void QDlgPrint::doPrintPreview()
{
	QPrinter printer(QPrinter::HighResolution);

	// ������ӡԤ���Ի���
	QPrintPreviewDialog preview(&printer, this);
	preview.setMinimumSize(1000, 600);

	// ��Ҫ����Ԥ��ҳ��ʱ������paintRequested()�ź�
	connect(&preview, SIGNAL(paintRequested(QPrinter*)), this, SLOT(printPreview(QPrinter*)));
	preview.exec();
}

void QDlgPrint::createPDF()
{
	QString fileName = QFileDialog::getSaveFileName(this, QStringLiteral("����PDF�ļ�"), QString(), "*.pdf");
	if (!fileName.isEmpty())
	{
		// ����ļ���׺Ϊ�գ���Ĭ��ʹ��.pdf
		if (QFileInfo(fileName).suffix().isEmpty())
			fileName.append(".pdf");

		QPrinter printer;
		// ָ�������ʽΪpdf
		printer.setOutputFormat(QPrinter::PdfFormat);
		printer.setOutputFileName(fileName);
		QMessageBox::information(this, QStringLiteral("����PDF"), QStringLiteral("����PDF�ļ��ɹ�"), QMessageBox::Ok);
	}
}

void QDlgPrint::printPreview(QPrinter* p)
{

}
