// ******************************************************
// * copyright (C) 2020 by rbehm@ibb-aviotec.com
// * File: main.cpp
// * created 2020-02-14 with pro-config V0.1
// ******************************************************

#include "mainwindow.h"
#include "config.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setApplicationName("propOVL");
	app.setApplicationVersion("V0.1");
	app.setOrganizationDomain("ibb-aviotec.com");
	app.setOrganizationName("IBB-aviotech");
//	QString fileName;
	{
		const QString logo(":/logo/ibb-logo");
		app.setProperty("copyright-icon", logo);
		app.setWindowIcon(QIcon(":/logo.png"));
	}
	{
		QCommandLineParser parser;
		parser.setApplicationDescription(app.applicationName());
		parser.addHelpOption();
		parser.addVersionOption();
//		parser.addPositionalArgument("file", "file-name");
		parser.process(app);
//		if (! parser.positionalArguments().isEmpty())
//		{
//			fileName = parser.positionalArguments().first();
//		}
	}
//	{
//		QFile sf(":/styles.css");
//		sf.open(QIODevice::ReadOnly);
//		app.setStyleSheet(sf.readAll());
//	}
	Config::loadDefaults();
	MainWindow mw;
	mw.show();
	return app.exec();
}

