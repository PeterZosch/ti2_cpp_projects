#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

//Funktionsprototypen

void fileHandling(int);
void tableFunc();

void inlineEdit();
void changeLine();
void insertLine();
void deleteLine();
void searchString();

int main()
{
	char key;
	int mode=0; // 0=open, 1=save
	do{
		system("clear");

		cout << endl << "Hautpmenue";
		cout << endl << "----------";
		cout << endl <<	"(o) Datei oeffnen";
		cout << endl << "(t) Tabellenfunktion";
		cout << endl << "(q) Quit";
		
		cout << endl << (">");
		cin.ignore();
		cin >> key;

		switch(key){
			case 'o':	fileHandling(mode);
					break;
			
			case 't':	inlineEdit();
					break;

			case 'q':	return 0;
			
			default :	cout << "Falsche Eingabe";
//					nanosleep(1000);
		}
	}while(key != 'q');

	return 0;
}

/* Funktion um eine Datei zu öffnen und speichern, falls noch nicht vorhanden 
   wird sie Erstellt.

   Datei existiert und besitzt Inhalt:
	Zeilen werden gezählt und als pointer zur Verfügung gestellt
	Der inhalt wird in den Hauptspeicher gelesen vi der Vector-Klasse
        und die Datei geschlossen

   Datei existiert nicht:
	Vector-Klasse wird erstellt aber ohne Inhalt */

void fileHandling(int mode)
{
	
}

void inlineEdit()
{
	int next=1;   
	char key;	

	do{
		system("clear");
		cout << "(r)ück, (v)or | (a)endern, (e)infuegen, (l)oeschen, (s)uchen | sa(v)e | (b)ack";
		cout.fill ('-');
		cout.width (80);
	
        	for(int i = 1; i <= lines; i++){
            		getline(inputf, buffer);
            		if( i == vor){
                		cout << i << "\t" << buffer << endl;
            		}else if(vor > lines){
                		cout << "Dateiende" << endl;
                		break;
            		}
        	}

/*	for(i(= 1; i <= *p_lineCnt; i++){
        	if (fgets(streambuffer, sizeof(streambuffer), stream) != NULL && i == next ){
                    printf("\n Z%i  %s\n", i, streambuffer);
                    aktline++;
				}
				else if(next>*p_lineCnt){
					printf("\n ***Dateiende***\n");
					break;
				}
                
            }
	cout << " ****************************************************************************";            
*/
//		cout <<"";	
		cout.fill ('-');
		cout.width (80);
        	cout << endl << "\n>";
		cin.ignore();
           	cin >> key;
            	
		switch(key){
                	case 'v':	next++;
//					if (next>=*p_lineCnt+1){
//						next=*p_lineCnt+1;}
                    			break;
               		
			case 'r':	next--;
//                			if (next<=1){
//                				next=1;}
                    			break;
              		
//			case 'a':	changeLine();
//                			aktline=0;
//					break;

//			case 'e':	insertLine();
//                			aktline=0;
//					break;	

//			case 'l':	deleteLine();
//                			aktline=0;
//					break;
		
//			case 's':	searchString();
//					break;												
        
//			case 'v':	mode = 1	 //speichermodus aktivieren
//					fileHandling(mode);
//					break;												

		      	case 'b':	return 0;
	
			default:	cout << "Falsche Eingabe";
		}
	}while(key != 'q');
}
