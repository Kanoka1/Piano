#include "piano.h"
#include <QtWidgets/QApplication>
#include "SoundPlayer.h"

#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
//	new SoundPlayer(44100);
	QApplication a(argc, argv);
	Piano w;
	w.show();
	return a.exec();
}