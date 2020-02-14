// ******************************************************
// * copyright (C) 2020 by rbehm@ibb-aviotec.com
// * File: mainwindow.cpp
// * created 2020-02-14 with pro-config V0.1
// ******************************************************

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"
#include "srctable.h"
#include "filenamehandler.h"

MainWindow::MainWindow(QString filename, QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
	, m_srcModel(new SrcTable(this))
{
	ui->setupUi(this);
	if  (filename.isEmpty())
	{
		m_srcModel->loadConf(Config::conf());
	}
	else
	{
		SpinSrc row;
		FilenameHandler fnh(filename, "spin");
		row.src = fnh.fullname();
		fnh.setExt("dat");
		row.out = fnh.fullname();
		SpinSrcVector rows( { row } );
		m_srcModel->setData(rows);
	}
	SpinSrcVector rows =  m_srcModel->data();
	for (int row = 0; row < rows.count(); ++row)
	{
		rows[row].result = "Unknown";
		rows[row].resultCode = -1;
	}
	m_srcModel->setData(rows);
	ui->srcView->setModel(m_srcModel);
}

MainWindow::~MainWindow()
{
	m_srcModel->saveConf(Config::conf());
	delete ui;
}

void MainWindow::quit()
{
	close();
}


void MainWindow::on_actionOpen_triggered()
{
	QString filename = QFileDialog::getOpenFileName(this, "Select SPIN src",
							Config::stringValue("src/name", qApp->applicationDirPath()),
							"*.spin");
	if (! filename.isEmpty())
	{
		Config::setValue("src/name", filename);
//		m_db->open(filename);
	}

}

void MainWindow::on_actionSave_triggered()
{
	QString filename = QFileDialog::getSaveFileName(this, "Select data output",
							Config::stringValue("obj/name", qApp->applicationDirPath()),
							"*.dat");
	if (! filename.isEmpty())
	{
		Config::setValue("obj/name", filename);
//		m_db->exportCsv(filename);
	}
}
