
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
				 Fehlerbehandlung eingef�gt
				 
	Die wichtigsten Methoden:
	
	double Get_wert(void)	// gibt Wert von Bautei zur�ck
	void Set_wert(double)	// setzt wert von Bautei
	void Restet(void)		// l�scht die vergangenheit von Bauteil
	void Set_i(double)		// pusht i_wert in member vector
	void Set_u(double)		// pusht u_wert in member vector

	double Get_i(void)		// gibt i_wert zur�ck	
	double Get_u(void)		// gibt u_wert zur�ck	

	void berechne_neu()		// berechnet neue werte und pusht in vector

	*/
/* -------------------------------------
   Abstrakt:	Ausfuehrliche Beschreibung des Inhalts der Implementierungsdatei
			
   Alle Funktionen:	keine
   Parameter: keine

   ------------------------------------- */

// serRLC_Aufgabe_2.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//
#include "StdAfx.h"
#include "Widerstand.h"

//ist inline geschrieben
/*CWiderstand::CWiderstand(void)
{
}
*/

CWiderstand::~CWiderstand(void)
{
}
