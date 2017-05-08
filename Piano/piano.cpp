#include "piano.h"
#include <string>
#include "SoundPlayer.h"

Piano::Piano(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.NoteC, &QPushButton::clicked, [this] { setText(0); });
	connect(ui.NoteCb, &QPushButton::clicked, [this] { setText(1); });
	connect(ui.NoteD, &QPushButton::clicked, [this] { setText(2); });
	connect(ui.NoteDb, &QPushButton::clicked, [this] { setText(3); });
	connect(ui.NoteE, &QPushButton::clicked, [this] { setText(4); });
	connect(ui.NoteF, &QPushButton::clicked, [this] { setText(5); });
	connect(ui.NoteFb, &QPushButton::clicked, [this] { setText(6); });
	connect(ui.NoteG, &QPushButton::clicked, [this] { setText(7); });
	connect(ui.NoteGb, &QPushButton::clicked, [this] { setText(8); });
	connect(ui.NoteA, &QPushButton::clicked, [this] { setText(9); });
	connect(ui.NoteAb, &QPushButton::clicked, [this] { setText(10); });
	connect(ui.NoteB, &QPushButton::clicked, [this] { setText(11); });
}

Piano::~Piano()
{

}

void Piano::setText(int param)
{
	m_soundPlayer.PlaySoundW(param);
}