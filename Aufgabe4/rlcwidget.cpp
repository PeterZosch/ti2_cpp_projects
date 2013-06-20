#include "rlcwidget.h"

//Eigene Klassen
#include "elements.h"

#include <vector>
//Defaultwerte für R, L, C, Ue
#define STD_R 10
#define STD_L 20
#define STD_C 0.5
#define STD_UE 10

int	click = 0;

//Abgeleitete Klassen
class Resistor : public Elements {
};

class Inductor : public Elements {
};

class Capacitor : public Elements {
};

void RLCWidget::paintEvent( QPaintEvent *event )
{

    //create a QPainter and pass a pointer to the device.
    //A paint device can be a QWidget, a QPixmap or a QImage
    QPainter painter(this);
 
    //create a black pen that has solid line
    //and the width is 2.
    QPen myPen(Qt::black, 2, Qt::SolidLine);
    painter.setPen(myPen);

	painter.drawLine( 100, 480, 1150, 480 ); 	
	painter.drawLine( 100, 480, 100, 50 ); 	

	//Pfeilspitze Y achse
	painter.drawPoint( 98, 52 ); 	
	painter.drawPoint( 96, 54 ); 	
	painter.drawPoint( 101, 52 ); 	
	painter.drawPoint( 103, 54 ); 	
    
	//Pfeilspitze X achse
	painter.drawPoint( 1147, 478 ); 	
	painter.drawPoint( 1145, 476 ); 	
	painter.drawPoint( 1147, 482 ); 	
	painter.drawPoint( 1145, 484 ); 	

	QPen myPen2(Qt::black, 2, Qt::DashDotDotLine);
	painter.setPen(myPen2);
	
	painter.drawLine( 92, 230, 1150, 230 ); 	

	QFont font("Courier", 10 );
	painter.setPen( Qt::black );
	painter.setFont(font);

	painter.drawText( 60, 230, "10V"); 
	painter.drawText( 60, 55, "U/V"); 
	painter.drawText( 1140, 500, "Time"); 

	//Wenn mouse einmal geklickt dann graphen berechnen und zeichnen 
	if ( click == 1 ) {	
    
		compute();
		QPen myPen1(Qt::red, 2, Qt::SolidLine);
    	painter.setPen(myPen1);
		painter.drawPolyline(rlccurve);
	}

}

void RLCWidget::compute()
{
    int x = 0;
    int Ue = STD_UE;
    Resistor r1;
    Inductor l1;
    Capacitor c1;

    r1.Set_Value( STD_R );
    l1.Set_Value( STD_L );
    c1.Set_Value( STD_C );

    c1.Set_Voltage( 0 );
    l1.Set_Ampere( 0 );

    for ( int i = 0 ; i <= 100 ; i++ ) {

        r1.Set_Ampere( l1.Get_Ampere() );
        r1.Set_Voltage( r1.Get_Ampere() * r1.Get_Value() );
        l1.Set_Voltage( Ue - r1.Get_Voltage() - c1.Get_Voltage() );
        c1.Set_Ampere( l1.Get_Ampere() );
        c1.Set_Voltage( c1.Get_Voltage() + (c1.Get_Ampere() / c1.Get_Value()) );
        l1.Set_Ampere( l1.Get_Ampere() + (l1.Get_Voltage() / l1.Get_Value()) );
    }

    for ( Capacitor::iterator it = c1.beginV() ; it != c1.endV() ; ++it ) {
        rlccurve << QPointF( ( 100 + (x * 10) ) , ( 480 - (*it * 25) ));
        x++;

    }

}

void RLCWidget::mousePressEvent ( QMouseEvent * e )
{
    // store click position
    m_lastPoint = e->pos();
    // set the flag meaning "click begin"
    m_mouseClick = true;
}

void RLCWidget::mouseReleaseEvent ( QMouseEvent * e )
{
    // check if cursor not moved since click beginning
    if ((m_mouseClick) && (e->pos() == m_lastPoint))
    {
		click++;	
        // do something: for example emit Click signal
		if ( click <= 1 ) {
			repaint();
		}

    }
}
