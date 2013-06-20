#include <QtGui>
#include "mywidget.h"
 
int main( int argc, char **argv )
{
	QApplication app( argc, argv );
 
	MyWidget myWidget;
	
	myWidget.resize(1200, 600);
	myWidget.setWindowTitle("RLC-Simulator-Stinkt!");
 	myWidget.show();
 
  return app.exec();
}
