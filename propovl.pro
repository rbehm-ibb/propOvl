# // ******************************************************
# // * copyright (C) 2020 by Reinhardt Behm/rbehm@hushmail.com
# // * All Rights reserved
# // ******************************************************

TEMPLATE = app

include( $$[PRTEMPLATE]/project.pri)
include( $$[PRTEMPLATE]/lib/QHexView/qhexview.pri)
include( $$[PRTEMPLATE]/lib/utils/config.pri)
include( $$[PRTEMPLATE]/lib/utils/filenamehandler.pri)
include( $$[PRTEMPLATE]/lib/utils/ibb-logo.pri)
include( $$[PRTEMPLATE]/lib/utils/ibtoolbar.pri)
include( $$[PRTEMPLATE]/lib/utils/stdicons.pri)

TARGET = propovl

QT +=

DEFINES += 

HEADERS += \
	datcompiler.h \
	mainwindow.h

SOURCES += \
	datcompiler.cpp \
	main.cpp \
	mainwindow.cpp

FORMS += \
	mainwindow.ui

RESOURCES += \
	rsc/rsc.qrc

DISTFILES += \
	.gitignore \
	rsc/logo.png \
	rsc/defaults.rc \
	rsc/styles.css

