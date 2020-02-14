// ******************************************************
// * copyright (C) 2020 by rbehm@ibb-aviotec.com
// * File: mainwindow.cpp
// * created 2020-02-14 with pro-config V0.1
// ******************************************************

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
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
