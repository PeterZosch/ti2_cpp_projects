#include "elements.h"

void Elements::Set_Value( double newValue )
{
    if( newValue <= 0  ) {
        throw ( char* ) "Eingegebener Wert für den R ist ungültig !" ;
    }
    value = newValue;
}
