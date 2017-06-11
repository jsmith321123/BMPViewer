#define __USE_MINGW_ANSI_STDIO 0

#include "MainWindow.h"

MainWindow::MainWindow() {
	layout.addWidget(is->view);
	central_widget.setLayout(&layout);

	setCentralWidget(&central_widget);
}