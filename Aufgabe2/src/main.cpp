#include <iostream>
#include <vector>
#include <cstdlib>
#include "resistor.h"
#include "capacitor.h"
#include "inductor.h"

#define STD_R 10
#define STD_L 20
#define STD_C 0.5
#define STD_UE 10

using namespace std;

int changeValues();
int calculateUc(Resistor &r1, Inductor &l1, Capacitor &c1, double &Ue);
void history();

int main() 
{
	Resistor r1;
	Inductor l1;
	Capacitor c1;

	r1.Set_Value( STD_R );
	l1.Set_Value( STD_L );
	c1.Set_Value( STD_C );

	double Ue = STD_UE;

	char key = 'q';

	c1.Set_Voltage( 0 );
	l1.Set_Ampere( 0 );


	do{
		system("clear");

        cout << endl << "Hautpmenue";
        cout << endl << "----------";
        cout << endl << "(c) Anzeigen und Ändern der Bauteileigenschaften";
        cout << endl << "(a) Ausgabe Uc";
        cout << endl << "(h) Historien";
        cout << endl << "(q) Quit";

        cout << endl << (">");

        cin.get(key);
        cin.ignore();

        switch(key){

            case 'c':	changeValues();	
                    	break;

            case 'a':	calculateUc(r1, l1, c1, Ue);	
                    	break;
            
			case 'h':	cout << "Historien Funktion" << endl;
                    	break;

            case 'q':   return 0;

        }
    }while(key != 'q');

	return 0;
}


int changeValues()
{

}


int calculateUc(Resistor &r1, Inductor &l1, Capacitor &c1, double &Ue)
{
	char key;
	
	for ( int i = 0 ; i <= 100 ; i++ ) {

		r1.Set_Ampere( l1.Get_Ampere() );
		r1.Set_Voltage( r1.Get_Ampere() * r1.Get_Value() );
		l1.Set_Voltage( Ue - r1.Get_Voltage() - c1.Get_Voltage() );
		c1.Set_Ampere( l1.Get_Ampere() );
		c1.Set_Voltage( c1.Get_Voltage() + ( c1.Get_Ampere() / c1.Get_Value() ) );
		l1.Set_Ampere( l1.Get_Ampere() + ( l1.Get_Voltage() / l1.Get_Value() ) );

		cout << c1.Get_Voltage() << endl;
	}
	
	cout << "\nWollen Sie die Ausgabe in eine Datei speichern? (y/n)" << endl;
    cout << endl << (">");
    cin.get(key);
    cin.ignore();

	if ( key == 'y' ) {
		cout << "FileHandler aufruf" << endl;
	} else {
		return 0;
	}
}
