// ******************************************************
// * copyright (C) 2020 by rbehm@ibb-aviotec.com
// * File: mainwindow.h
// * created 2020-02-14 with pro-config V0.1
// ******************************************************

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

public slots:
	void quit();
private slots:
	void on_actionOpen_triggered();

	void on_actionSave_triggered();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

