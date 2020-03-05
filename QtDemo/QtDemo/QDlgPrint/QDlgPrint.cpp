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
	QAction *action_print = new QAction(QStringLiteral("打印"), this);
	QAction *action_printPreview = new QAction(QStringLiteral("打印预览"), this);
	QAction *action_pdf = new QAction(QStringLiteral("生成pdf"), this);

	connect(action_print, SIGNAL(triggered()), this, SLOT(doPrint()));
	connect(action_printPreview, SIGNAL(triggered()), this, SLOT(doPrintPreview()));
	connect(action_pdf, SIGNAL(triggered()), this, SLOT(createPDF()));

	ui.mainToolBar->addAction(action_print);
	ui.mainToolBar->addAction(action_printPreview);
	ui.mainToolBar->addAction(action_pdf);
}

void QDlgPrint::doPrint()
{
	// 创建打印机对象
	QPrinter printer;
	QString printerName = printer.printerName();

	if (printerName.size() == 0)
	{
		QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("没有找到打印机"));
		return;
	}

	QPrintDialog dlg;

	if (dlg.exec() == QDialog::Accepted)
	{
		QTextDocument doc;
		QFont font = doc.defaultFont();
		font.setPointSize(3);
		doc.setDefaultFont(font);
		//打印尺寸
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

	// 创建打印预览对话框
	QPrintPreviewDialog preview(&printer, this);
	preview.setMinimumSize(1000, 600);

	// 当要生成预览页面时，发射paintRequested()信号
	connect(&preview, SIGNAL(paintRequested(QPrinter*)), this, SLOT(printPreview(QPrinter*)));
	preview.exec();
}

void QDlgPrint::createPDF()
{
	QString fileName = QFileDialog::getSaveFileName(this, QStringLiteral("导出PDF文件"), QString(), "*.pdf");
	if (!fileName.isEmpty())
	{
		// 如果文件后缀为空，则默认使用.pdf
		if (QFileInfo(fileName).suffix().isEmpty())
			fileName.append(".pdf");

		QPrinter printer;
		// 指定输出格式为pdf
		printer.setOutputFormat(QPrinter::PdfFormat);
		printer.setOutputFileName(fileName);
		QMessageBox::information(this, QStringLiteral("生成PDF"), QStringLiteral("保存PDF文件成功"), QMessageBox::Ok);
	}
}

void QDlgPrint::printPreview(QPrinter* p)
{

}
