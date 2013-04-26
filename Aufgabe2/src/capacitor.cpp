#include "capacitor.h"


void Capacitor::Set_Value( double newValue )
{
	if( newValue <= 0  ) {
		throw "Eingegebener Wert für den C ist ungültig !" ;
    }
    valueC = newValue;
}
