
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
// stdafx.h : Includedatei für Standardsystem-Includedateien
// oder häufig verwendete projektspezifische Includedateien,
// die nur in unregelmäßigen Abständen geändert werden.
//

#pragma once
#define ANFANGSWERT 0
#define C_STANDARD 0.5
#define L_STANDARD 20
#define R_STANDARD 5
#define UE 10

#define INTRO_DATEI		"serRLC.txt"
#define AUSGABE_DATEI	"ausgabe.txt"


#include "targetver.h"

#include "Widerstand.h"
#include "Spule.h"
#include "Kondensator.h"

//#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <fstream>
#include <string>
#include <fstream>

void intro(void);

// TODO: Hier auf zusätzliche Header, die das Programm erfordert, verweisen.
