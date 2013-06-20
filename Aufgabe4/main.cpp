#include <QtGui>
#include "rlcwidget.h"
 
int main( int argc, char **argv )
{
	QApplication app( argc, argv );
 
	RLCWidget rlcwidget;
	
	rlcwidget.resize(1200, 600);
	rlcwidget.setWindowTitle("RLC-Simulator by TaK");
 	rlcwidget.show();
 
  return app.exec();
}
