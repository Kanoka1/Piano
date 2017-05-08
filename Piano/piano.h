#ifndef PIANO_H
#define PIANO_H

#include <QtWidgets/QMainWindow>
#include "ui_piano.h"
#include "SoundPlayer.h"

class Piano : public QMainWindow
{
	Q_OBJECT

public:
	Piano(QWidget *parent = 0);
	~Piano();

private:
	SoundPlayer m_soundPlayer;
	Ui::PianoClass ui;

public slots:
	void setText(int param);	

};
#endif // PIANO_H
