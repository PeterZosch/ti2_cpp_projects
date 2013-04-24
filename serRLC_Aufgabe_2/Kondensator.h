
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


class CKondensator
{
	double C_wert;
	

	std::vector<double> uc,ic;
	
public :


	CKondensator(void);
	CKondensator(double dwert){ C_wert=dwert;}

	double Get_wert(void){ return C_wert; }
	void Set_wert(double dwert);

	void Restet(){uc.clear();ic.clear();}

	void Set_i(double dineu){ ic.push_back(dineu);}
	void Set_u(double duneu){ uc.push_back(duneu);}

	double Get_i(){ return ic.at( ic.size() -1); }
	double Get_u(){ return uc.at( uc.size() -1); }

	void berechne_neu( )
	{ uc.push_back( Get_u() + ( Get_i()/C_wert) );}


	std::vector<double> Get_vec_u(){return uc;}
	std::vector<double> Get_vec_i(){return ic;}

	
	~CKondensator(void);
};

