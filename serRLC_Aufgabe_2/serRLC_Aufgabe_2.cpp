
/* -------------------------------------
   Bezeichnung des Inhalts der Datei
   (C) Name des Entwicklers, Datum
   Krafft Bernd , 17.04.2012 , http://byteKRAFT.de
    
   ------------------------------------- */
	/*
	17.04.12	-Klassen erstellt:
					-CKondensator
					-CSpule
					-CWiderstand
	24.04.12	-throw, try, catch
				 Fehlerbehandlung eingefügt
				 
	Die wichtigsten Methoden:
	
	double Get_wert(void)	// gibt Wert von Bautei zurück
	void Set_wert(double)	// setzt wert von Bautei
	void Restet(void)		// löscht die vergangenheit von Bauteil
	void Set_i(double)		// pusht i_wert in member vector
	void Set_u(double)		// pusht u_wert in member vector

	double Get_i(void)		// gibt i_wert zurück	
	double Get_u(void)		// gibt u_wert zurück	

	void berechne_neu()		// berechnet neue werte und pusht in vector

	*/
/* -------------------------------------
   Abstrakt:	Ausfuehrliche Beschreibung des Inhalts der Implementierungsdatei
			
   Alle Funktionen:	keine
   Parameter: keine

   ------------------------------------- */

// serRLC_Aufgabe_2.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	system("color a"); // Textfarbe neongrün

	CWiderstand r1;
	CKondensator c1;
	CSpule l1;
	double ue=UE;

	int cEingabe=-1;
	while(cEingabe!=0) //Menüschleife
	{
		try
		{
			system("cls");
			intro();		// intro aus Datei lesen
		
			std::cout<<"    R1= "<<r1.Get_wert()<<" Ohm  L1= "<< 
			l1.Get_wert()<<" Henri   C1= "<<c1.Get_wert()<<"Farad"<<"  UE= "<<ue<<" Volt\n\n\n";

			std::cout<<"\t<1> Anzeige und Aenderung der Parameterwerte der Schaltung\n";
			std::cout<<"\t<2> Durchfuehrung der Simulation mit Ausgabe\n";
			std::cout<<"\t<0> Ende\n\n\tEingabe: ";

			std::fflush(stdin);// unschöne Fehlerbehebung laut Stefan!!
			std::cin.clear();

			std::cin>>cEingabe;
	
			switch(cEingabe)
			{
			case 0:
				{
					std::cout<<"\n\tProgramm beendet!!!\n\n\t";
					system("pause");
					break;
				}
			case 1:
				{//Anzeige und Aenderung der Parameterwerte der Schaltung
					system("cls");
					std::cout<<"\tAenderung der RLC-Parameterwerte der Schaltung\n\n";
					std::cout << "\t R1= "<< r1.Get_wert()<<" Ohm"<<std::endl;
					std::cout << "\t L1= "<< l1.Get_wert()<<" Henri"<<std::endl;
					std::cout << "\t C1= "<< c1.Get_wert()<<" Fahrad"<<std::endl;
					std::cout << "\t Ue= "<< ue<<" Volt"<<"\n\n\n";

					std::cout<<"\n\tGeben sie neue RLC-Werte ein!\n\tWiderstand R1(Ohm)= ";
				
					//std::cout<<"\n"<<cEingabe<<"\n";

					double dwert=1.8;
					std::cin>> dwert;
					//if(dwert>0)r1.Set_wert(dwert);
					
					try
					{
						r1.Set_wert(dwert); //Fehler wird in class Widerstand geTHROWt
					
						std::cout<<"\n\tSpule   L1(Henri)= ";
						std::cin>> dwert;
						/*if(dwert>0) */l1.Set_wert(dwert);

						std::cout<<"\n\tKondensator C1(Farad)= ";
						std::cin>> dwert;
						/*if(dwert>0)*/c1.Set_wert(dwert);

					
						std::cout<<"\n\tEingangsspannung UE(Volt)= ";
						std::cin>> ue;
				

						std::cout<<"\n\n\tDie neuen Werte sind:\n\n";
						
						std::cout << "\t R1= "<< r1.Get_wert()<<" Ohm"<<std::endl;
						std::cout << "\t L1= "<< l1.Get_wert()<<" Henri"<<std::endl;
						std::cout << "\t C1= "<< c1.Get_wert()<<" Fahrad"<<std::endl;
						std::cout << "\t Ue= "<< ue<<" Volt"<<"\n\n\n";

					}
					catch (char * c_error)
					{
						std::cout<<"\n\tFehler!\n\t"<<c_error;
						//system("pause");
					}


					system("pause");
					
					break;
				}
			case 2:
				{//Durchfuehrung der Simulation mit Ausgabe

					std::ofstream out(AUSGABE_DATEI,std::ios::out); //Datei stream öffnen
					if(!out) throw "\n\tDatei fuer die Ausgabe konnte nicht geoeffnet werden!\n\tist moglicherweise Schreibgeschuetzt!\n\n";
					
					c1.Restet(); //Bauteilvergangenheit löschen
					l1.Restet();
					r1.Restet();
						
					c1.Set_u(0); // init 
					l1.Set_i(0); // init 

					for(int k=0;k<=100;k++)
					{
					
						r1.Set_i(l1.Get_i()); //OK
						r1.Set_u(  r1.Get_wert() * r1.Get_i()  ); // OK			
						l1.Set_u(  ue - r1.Get_u() -c1.Get_u()  ); //OK		
						c1.Set_i( l1.Get_i() ); // OK				
						c1.berechne_neu( ); //OK					
						l1.berechne_neu( ); //OK

						std::cout<< "U_C1= "<<std::setw(10)<<c1.Get_u() << "\tU_R1= "<<std::setw(10)<< r1.Get_u() <<"\tI_L1=" <<std::setw(10)<< l1.Get_i() <<"\n";  
						out<<c1.Get_u()  << "\n"; // Ausgabe an Datei
				
					}	

					out.close(); // Datei schlißen

					// ########### Rausschreiben der Bauteilvergangenheit ################
					std::vector<double> uc=c1.Get_vec_u();// Vergangenheit des Bauteils in loc var schreiben

					int i=uc.size(); 
					for(int j=0;j<i-1;j++)
					{
						std::cout<<"\n"<<uc.at(j);
					}
					// ###################################################################
					system("pause");
					break;
				}

			case 3:
				{
					int kwert=0;
					std::cin>>kwert;

			

				}
			default:
				{
					std::cout<<"\n\tFalsche Eingabe!!!\n\n\t";
					system("pause");
			
					break;
				}
			}

		}
		catch(char * c_error)
		{
			std::cout<<c_error;
			system("pause");
		}
		catch ( ...)
		{

			std::cout<<"\n\tUnbekannter Fehler!";
			system("pause");
		}
	

	}

	return 0;
}

void intro(void)
{
	// --- Intro aus Datei auslesen --------------
	std::ifstream datei_in(INTRO_DATEI,std::ios::in);
	do{
		char str[200];
		datei_in.getline(str,200);
		std::cout<<str<<std::endl;
	}while(!datei_in.eof());
	//--------------------------------------------
}


					//r1.ir.push_back(l1.il.at(k));//	
					//r1.ur.push_back( r1.Get_wert() * r1.ir.at(k) );

					//l1.ul.push_back( ue - r1.ur.at(k) - c1.uc.at(k) );

					//c1.ic.push_back( l1.il.at(k) );
					//c1.uc.push_back( c1.uc.at(k) + ( c1.ic.at(k)/c1.Get_wert() ) );
					//l1.il.push_back( l1.il.at(k) + ( l1.ul.at(k)/l1.Get_wert() ) );

					//std::cout<<c1.uc.at(k) << "\n"; 
					//out<<c1.uc.at(k) << "\n";