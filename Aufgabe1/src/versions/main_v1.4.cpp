#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

vector<string>::iterator it;

//Funktionsprototypen

int fileHandling(int mode);
void tableFunc();

int inlineEdit(vector<string> &stringVec, char *iFile, int mode);
void changeLine();
int insertLine(vector<string> &stringVec, vector<string>::iterator &it, string newString, unsigned int aktLine);
int deleteLine(vector<string> &stringVec, vector<string>::iterator &it, unsigned int aktLine);
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
			
//			case 't':	tableFunc();
//					break;

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

int fileHandling(int mode)
{
    
    string buffer;
    char choice, fileName[40];
    
    vector<string> stringVec;
    
    ifstream iFile;
    ofstream oFile;
    
    if(mode == 0){                  //Öffnen
        cout << endl << "Dateinamen eingeben" << endl;
        cout << "> ";
        cin.ignore();
        cin >> fileName;
        
        iFile.open(fileName);
        
        if(!iFile){
            cout << endl << "Datei existiert nicht !" << endl;
            cout << " Diese Datei erzeugen? (y/n)" << endl << "> ";
            cin.ignore();
            cin.get(choice);
            
            if (choice == 'y'){
	    }else if(choice == 'n'){
                return 0;
            }
        }

        
        while(getline(iFile, buffer)){
            
            stringVec.push_back(buffer);
        
        }
        
        iFile.close();
        
        inlineEdit(stringVec, fileName, mode);
        
    }else if(mode == 1){            //Speichern
    
        oFile.open(fileName);
    
        for (it = stringVec.begin(); it != stringVec.end(); ++it){
        
            oFile << *it;
        }
        
        oFile.close();
        
        cout << "Datei " << fileName << "geschreiben" << endl;
        
    }	
    return 0;
}

int inlineEdit(vector<string> &stringVec, char *iFile, int mode)
{   
	char key;
	unsigned int aktLine = 1;
	string newString;

	it = stringVec.begin();

	do{
		system("clear");
		cout << "(r)ück, (v)or | (a)endern, (e)infuegen, (l)oeschen, s(u)chen | (s)ave | (b)ack\n";
		cout << "------------------------------------------------------------------------------";
		cout << "\n";

                	cout << " " << *it << "\n";
		
		cout << "------------------------------------------------------------------------(" << aktLine << "/" << stringVec.size() << ")";
        
		cout << "\n>";
		cin.ignore();
           	cin >> key;
		
		switch(key){
			case 'v':	aktLine++;
					if(aktLine <= stringVec.size()){
						++it;
					}else{
						aktLine = stringVec.size();
					}
                    			break;
               		
			case 'r':	aktLine--;
					if(it == stringVec.begin()){
						it = stringVec.begin();
						aktLine=1;
					}else{
						--it;
					}
                    			break;
              		
//			case 'a':	changeLine();
//                			aktline=0;
//					break;

			case 'e':	cout << "\nNeue Zeile einfügen\n>";
					cin.ignore();
					getline(cin, newString);
					aktLine = insertLine(stringVec, it, newString, aktLine);
					break;	

			case 'l':	aktLine = deleteLine(stringVec, it, aktLine);
					
					break;
		
//			case 'u':	searchString();
//					break;												
        
			case 's':	mode = 1;	 //speichermodus aktivieren
					fileHandling(mode);
					break;												

		      	case 'b':	return 0;
	
			default:	cout << "Falsche Eingabe";
		}
	}while(key != 'q');
	
	return 0;
}



int insertLine(vector<string> &stringVec, vector<string>::iterator &it, string newString, unsigned int aktLine)
{
	++it;		//damit nach der aktuellen Zeile der newString eingefügt wird	
	stringVec.insert(it, newString);
	aktLine++;
	return aktLine;	
}


int deleteLine(vector<string> &stringVec, vector<string>::iterator &it, unsigned int aktLine)
{

}
