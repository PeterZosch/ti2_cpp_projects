#include "resistor.h"

void Resistor::Set_Value( double newValue )
{
    if( newValue <= 0  ) {
        throw ( char* ) "Eingegebener Wert für den R ist ungültig !" ;
    }
    valueR = newValue;
}
