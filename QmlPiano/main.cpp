#include "qmlpiano.h"
#include <QtWidgets/QApplication>

#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickItem>
#include <QtQuick/QQuickView>

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QQuickView *view = new QQuickView();
	view->setSource(QUrl::fromLocalFile("qml/testsignal/main.qml"));
	QObject *rect = dynamic_cast<QObject*>(view->rootObject());
	//SignalslotlistView myClass;
	//QObject::connect(rect, SIGNAL(qmlSignal(QString)),
	//	&myClass, SLOT(cppSlot(QString)));
	view->show();
	return app.exec();
}
