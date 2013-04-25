#include "resistor.h"
#include <iostream>

void Resistor::Set_Value(double newValue)
{
	if( newValue <= 0  ) { 
        throw "Eingegebener Wert für den R ist ungültig !" ;
	}
    valueR = newValue;
}
