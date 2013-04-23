#include <iostream>
#include <vector>
#include "resistor.h"
#include "capacitor.h"
#include "inductor.h"

#define STD_R 10
#define STD_L 20
#define STD_C 0.5
#define STD_UE 10

using namespace std;

int main() 
{
	Resistor 	r1;
	Inductor 	l1;
	Capacitor c1;

	r1.Push_Value( STD_R );
	l1.Push_Value( STD_L );
	c1.Push_Value( STD_C );

	double Ue = STD_UE;

	c1.Push_Voltage( 0 );
	l1.Push_Ampere( 0 );

	for ( int i = 0 ; i <= 100 ; i++ ) {
		
		r1.Push_Ampere( l1.Pull_Ampere() );
		r1.Push_Voltage( r1.Pull_Ampere() * r1.Pull_Value() );
		l1.Push_Voltage( Ue - r1.Pull_Voltage() - c1.Pull_Voltage() );
		c1.Push_Ampere( l1.Pull_Ampere() );
		c1.Push_Voltage( c1.Pull_Voltage() + (
						 c1.Pull_Ampere() / c1.Pull_Value() ) );
		l1.Push_Ampere( l1.Pull_Ampere() + (
						l1.Pull_Voltage() / l1.Pull_Value() ) );

		cout << c1.Pull_Voltage() << endl;
	}

	return 0;
}
