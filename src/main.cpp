#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "mainWindow.h"

int main(int argc, char** argv) {
	//init application
	QApplication app(argc, argv);

	MainWindow win;
	win.resize(320, 240);
	win.setVisible(true);

	//execute event loop
	return app.exec();
}
