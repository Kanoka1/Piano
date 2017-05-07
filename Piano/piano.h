#ifndef PIANO_H
#define PIANO_H

#include <QtWidgets/QMainWindow>
#include "ui_piano.h"

constexpr float FrequencyNoteC = 261.63f;
constexpr float FrequencyNoteCb = 277.18;
constexpr float FrequencyNoteD = 293.66f;
constexpr float FrequencyNoteDb = 311.13f;
constexpr float FrequencyNoteE = 329.63f;
constexpr float FrequencyNoteF = 349.23f;
constexpr float FrequencyNoteFb = 369.99f;
constexpr float FrequencyNoteG = 392.00f;
constexpr float FrequencyNoteGb = 415.30f;
constexpr float FrequencyNoteA = 440.00f;
constexpr float FrequencyNoteAb = 466.16f;
constexpr float FrequencyNoteB = 493.88f;

class Piano : public QMainWindow
{
	Q_OBJECT

public:
	Piano(QWidget *parent = 0);
	~Piano();

private:
	Ui::PianoClass ui;

public slots:
void setText(const char * text);
void setText(float param);

};
#endif // PIANO_H
