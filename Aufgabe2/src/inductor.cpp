#include "inductor.h"

void Inductor::Set_Value( double newValue )
{
    if( newValue <= 0  ) {
        throw ( char* ) "Eingegebener Wert für den L ist ungültig !" ;
    }
    valueL = newValue;
}
