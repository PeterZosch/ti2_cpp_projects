#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

vector<string>::iterator it;

//Funktionsprototypen
int FileHandling( vector<string> &stringVec, char *fileName, int mode );

int TableFunc( char *dName );

int InlineEdit( vector<string> &stringVec, char *iFile, int mode,
                 int newFile );

void ChangeLine( vector<string> &stringVec, string newString,
                unsigned int *p_aktLine );

void InsertLine( vector<string> &stringVec, vector<string>::iterator &it, 
               string newString, unsigned int *p_aktLine, int newFile );

void DeleteLine( vector<string> &stringVec, vector<string>::iterator &it, 
               unsigned int *p_aktLine );

void SearchString( vector<string> &stringVec, vector<string>::iterator &it, 
                 string newString, unsigned int *p_aktLine );




/*
===============================================================================
main

Hauptmenü zum öffnen einer Datei, oder zum öffnen der Tabellenfunktion
===============================================================================
*/
int main()
{
    char key;
	int  mode = 0;          // 0=open, 1=save
	char fileName[42];
	char dName[42];
   	
    vector<string> stringVec;
	
	do {
        system( "clear" );

		cout << endl << "Hautpmenue";
		cout << endl << "----------";
		cout << endl <<	"(o) Datei oeffnen";
		cout << endl << "(t) Tabellenfunktion";
		cout << endl << "(q) Quit";
		cout << endl << ( ">" );
		
        cin.get( key );
		cin.ignore();

		switch ( key ) {
			case 'o':	    mode = 0;
					        cout << endl << "Dateinamen eingeben" << endl;
    					    cout << "> ";
        				    cin >> fileName;	
					        FileHandling( stringVec, fileName, mode );
					        break;
			
			case 't':      	cout << "\nDateinamen eingeben" << endl << "> "; 
   					        cin >> dName;
				        	TableFunc( dName );
				        	break;

			case 'q':	    return 0;
		}

	} while ( key != 'q' );

	return 0;
}


/*
===============================================================================
FileHandling

Öffnen einer Datei, zeilenweise einlesen in Vektoren, und schließen der Datei
gesamte Datei ist dadurch im Hauptspeicher und kann beliebig manipuliert
werden
Speichern: erneutes öffnen der Datei und gesamten Inhalt im Hauptspeicher
           in Datei schreiben.
===============================================================================
*/
int FileHandling( vector<string> &stringVec, char *fileName, int mode )
{
	string null = ""; 
   	string buffer;
   	char   choice;
   	string enter;
   	int    newFile = 0;
 
   	ifstream iFile;
   	ofstream oFile;
    
    if ( mode == 0 ) {                  //Öffnen
	    stringVec.clear(); 
       	iFile.open( fileName );
        
        if ( !iFile ) {
            cout << endl << "Datei existiert nicht !" << endl;
           	cout << " Diese Datei erzeugen? (y/n)" << endl << "> ";
           	cin.ignore();
	    	cin.get( choice );            
            
           	if ( choice == 'y' ) {
				stringVec.push_back( null );
	       		newFile = 1;
				iFile.close();
	       		InlineEdit( stringVec, fileName, mode, newFile );
				return 0;
	
	    	} else if ( choice == 'n' ) {
               	return 0;
           	}
        }

        while ( getline( iFile, buffer ) ) {
           	stringVec.push_back( buffer );
       	}
       	iFile.close();
       	InlineEdit( stringVec, fileName, mode, newFile );

    } else if ( mode == 1 ) {            //Speichern
        oFile.open( fileName );

        for ( it = stringVec.begin() ; it != stringVec.end() ; ++it ) {
        		oFile << *it << endl;
       	}	

       	oFile.close();

		it = stringVec.begin(); 
       	
        system("clear");
		cout << "Datei " << "'" << fileName << "'" << " geschrieben" << endl;
    	cout << "\n\n\nplease press Return to continue" << endl;
   		cin.ignore(); 
		getline( cin, enter );
       	
    	InlineEdit( stringVec, fileName, mode, newFile );
   	}
   	return 0;
}


/*
===============================================================================
InlineEdit

Hauptfunktion zum inline Editieren der eingelesenen Textdatei
Funktionen:
    vorwärts und rückwärts Blättern
    aktuelle Zeile ändern
    neue Zeile einfügen
    aktuelle Zeile löschen
    Datei nach Suchbegriff durchsuchen
    Datei speichern
    zurück in das Hauptmenü
===============================================================================
*/
int InlineEdit( vector<string> &stringVec, char *fileName, int mode, 
                int newFile )
{   
	char         key;
	unsigned int aktLine = 1;
    unsigned int *p_aktLine = &aktLine;
	string       newString;
	string       anyKey;

	it = stringVec.begin();

	do {
		system( "clear" );
		
        cout << "(r)ück, (v)or | (a)endern, (e)infuegen, (l)oeschen, "
                "s(u)chen | (s)ave | (b)ack\n";
		cout << "----------------------------------------------------"
                "--------------------------";
		cout << "\n";
        
        cout << " " << *it << "\n";      //Zeilen ausgabe über Iterator
		
		cout << "-----------------------------------------------------"
                "-------------------(" << *p_aktLine << "/" 
             << stringVec.size() << ")";
		cout << "\n>";
           
		cin.get( key );
		cin.ignore();
		
		switch ( key ) {
			case 'v':       aktLine++;
					        if ( it != (stringVec.end() - 1 ) ) {
					        	++it;
				        	} else {
					        	it = stringVec.end() - 1;
						        aktLine = stringVec.size();
					        }
                    		break;
               		
			case 'r':   	aktLine--;
					        if ( it == stringVec.begin() ) {
						        it = stringVec.begin();
						        aktLine = 1;
					        } else {
						        --it;
					        }
                    		break;
              		
			case 'a':       cout << "\nAktuelle Zeile ändern\n>";
                            getline( cin, newString );
			        		ChangeLine( stringVec, newString, p_aktLine );
				        	break;

			case 'e':	    cout << "\nNeue Zeile einfügen\n>";
				        	getline( cin, newString );
			   	            InsertLine( stringVec, it, newString, p_aktLine,
                                        newFile );
				        	break;	

			case 'l':	    DeleteLine( stringVec, it, p_aktLine );
				        	break;
		
			case 'u':   	cout << "\nSuchstring eingeben\n>";
                            getline( cin, newString );
				            SearchString( stringVec, it, newString, p_aktLine );
				        	if ( aktLine == 4711 ) {
					        	cout << "\nSuchstring nicht gefunden - "
                                        "Press Return to continue\n";
					    	    getline( cin, anyKey );
						        *p_aktLine = 1;
					        }
					        break;												
        
			case 's':	    mode = 1;	 //speichermodus aktivieren
					        FileHandling( stringVec, fileName, mode );
					        return 0;												

	      	case 'b':	    return 0;
		}
	} while ( key != 'q' );
	return 0;
}


/*
===============================================================================
InsertLine

Fügt nach der angezeigten Zeile eine neue Zeile ein
===============================================================================
*/
void InsertLine( vector<string> &stringVec, vector<string>::iterator &it, 
                string newString, unsigned int *p_aktLine, int newFile )
{
	if ( newFile == 1 ) {
		stringVec.push_back( newString );
		( *p_aktLine )++;
	}
	++it;		//damit nach der aktuellen Zeile der newString eingefügt wird	
	stringVec.insert( it, newString );
	( *p_aktLine )++;
}


/*
===============================================================================
DeleteLine

löscht die aktuell angezeigte Zeile
===============================================================================
*/
void DeleteLine( vector<string> &stringVec, vector<string>::iterator &it,
                 unsigned int *p_aktLine )
{
	stringVec.erase( it );
	if ( *p_aktLine == stringVec.size() ) {
		( *p_aktLine )--;
		--it;
		it = stringVec.end() - 1;
	}
}


/*
===============================================================================
ChangeLine

Die aktuell angezeigte Zeile kann geändert werden (wird komplett ersetzt)
===============================================================================
*/
void ChangeLine( vector<string> &stringVec, string newString,
                 unsigned int *p_aktLine )
{
	stringVec[ *p_aktLine - 1 ] = newString;
}


/*
===============================================================================
SearchString

Durchsucht die Datei nach einem Suchbegriff.
    gefunden:       die Zeile in welcher der Suchbegriff gefunden wurde wird 
                    angezeigt
    nicht gefunden: eine Meldung wird ausgegeben
===============================================================================
*/
void SearchString( vector<string> &stringVec, vector<string>::iterator &it, 
                  string newString, unsigned int *p_aktLine )
{
	system( "clear" );
	*p_aktLine = 1;
	string buffer;

	for ( it = stringVec.begin() ; it != stringVec.end() ; ++it) {
		buffer = *it;
		if ( buffer.find( newString ) != buffer.npos ) {
		} else {
			( *p_aktLine)++;
		}
	}
	it = stringVec.begin();
	*p_aktLine = 4711;
}


/*
===============================================================================
TableFunc

Funktion zum einlesen einer Datei mit Zahlenwerten
    Berechnungen:
        Summe aller Zahlen
        Mittelwert der Zahlen
        Varianz
===============================================================================
*/
int TableFunc( char *dName )
{
	system( "clear" ); 
	double amt, mean, vrne, zahl, temp, sum;
           amt = mean = vrne = zahl = temp = sum = 0;	 
    string buffer, zosh;
    
   	ifstream tfile;
   	tfile.open(dName);
    
   	vector<int> numList;
    vector<int>::iterator it_1;
 
   	while ( getline( tfile, buffer ) ) {
       	zahl = atoi( buffer.c_str() );
       	numList.push_back( zahl );
   	}
    
   	amt = numList.size();
   	cout << "Zahlen der Datei:\n";
	 
   	for ( it_1 = numList.begin() ; it_1 != numList.end() ; ++it_1 ) {
       	cout << *it_1 << ", ";
       	sum += *it_1;
   	}
   
	cout << "\n";
   	cout << "\n\n\nSumme ist : " << sum;
    
   	amt = numList.size();
   	mean = sum / amt;
   	cout << "\n\nMittelwert ist : " << mean;
    
   	for ( it_1 = numList.begin() ; it_1 != numList.end() ; ++it_1 ) {
        	temp += ( *it_1 - mean ) * ( *it_1 - mean );
   	}
    
   	vrne = temp / amt;
   	cout << "\n\nVarianz ist : " << vrne << endl;
    
   	cout << "\n\n\nplease press Return to continue" << endl;
   	cin.ignore(); 
   	getline(cin, zosh);
    
   	return 0; 
}
	
// vim: et sw=4 ts=4