#ifndef QMLPIANO_H
#define QMLPIANO_H

#include <QtWidgets/QMainWindow>
#include "ui_qmlpiano.h"

class QmlPiano : public QMainWindow
{
	Q_OBJECT

public:
	QmlPiano(QWidget *parent = 0);
	~QmlPiano();

private:
	Ui::QmlPianoClass ui;
};

#endif // QMLPIANO_H
