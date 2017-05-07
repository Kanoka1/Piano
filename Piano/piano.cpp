#include "piano.h"
#include <string>
#include "SoundPlayer.h"

Piano::Piano(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.NoteC, &QPushButton::clicked, [this] { setText(FrequencyNoteC); });
	connect(ui.NoteCb, &QPushButton::clicked, [this] { setText(FrequencyNoteCb); });
	connect(ui.NoteD, &QPushButton::clicked, [this] { setText(FrequencyNoteD); });
	connect(ui.NoteDb, &QPushButton::clicked, [this] { setText(FrequencyNoteDb); });
	connect(ui.NoteE, &QPushButton::clicked, [this] { setText(FrequencyNoteE); });
	connect(ui.NoteF, &QPushButton::clicked, [this] { setText(FrequencyNoteF); });
	connect(ui.NoteFb, &QPushButton::clicked, [this] { setText(FrequencyNoteFb); });
	connect(ui.NoteG, &QPushButton::clicked, [this] { setText(FrequencyNoteG); });
	connect(ui.NoteGb, &QPushButton::clicked, [this] { setText(FrequencyNoteGb); });
	connect(ui.NoteA, &QPushButton::clicked, [this] { setText(FrequencyNoteA); });
	connect(ui.NoteAb, &QPushButton::clicked, [this] { setText(FrequencyNoteAb); });
	connect(ui.NoteB, &QPushButton::clicked, [this] { setText(FrequencyNoteB); });
}

Piano::~Piano()
{

}

void Piano::setText(float param)
{
	new SoundPlayer(param);
}

void Piano::setText(const char * text)
{
	ui.label->setText(QApplication::translate("PianoClass", "sd", 0));
}