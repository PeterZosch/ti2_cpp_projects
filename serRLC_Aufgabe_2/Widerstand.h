
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

class CWiderstand
{
	double R_wert;
	//double URakt;

	std::vector<double> ir,ur;
	 
public :

	CWiderstand(void){ R_wert=R_STANDARD;  }
	CWiderstand(double dwert){ R_wert=dwert;  }

	double Get_wert(void){ return R_wert; }
	void Set_wert(double dwert){ if(dwert<0)throw "R_wert darf nicht <0 sein!\n\tDer alte Wert wird beibehalten!\n\n";R_wert=dwert;}

	void Restet(){ur.clear(); ir.clear();}

	void Set_i(double dineu){ ir.push_back(dineu);}
	void Set_u(double duneu){ ur.push_back(duneu);}

	double Get_i(){ return ir.at( ir.size() -1); }
	double Get_u(){ return ur.at( ir.size() -1); }


	~CWiderstand(void);
};

