
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
#pragma once
#include <vector>
class CSpule
{
	double L_wert;
	
	std::vector<double> il,ul;

public :

	CSpule(void);
	CSpule(double dwert){ L_wert=dwert;  }

	double Get_wert(void){ return L_wert; }
	void Set_wert(double dwert);

	void Restet(){ul.clear();il.clear();}

	void Set_i(double dineu){ il.push_back(dineu);}
	void Set_u(double duneu){ ul.push_back(duneu);}

	double Get_i(){ return il.at( il.size() -1); }
	double Get_u(){ return ul.at( il.size() -1); }

	void berechne_neu( )
	{ il.push_back( Get_i() + ( Get_u()/L_wert) );}

	~CSpule(void);
};

