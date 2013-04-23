#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<string>::iterator it;

//Funktionsprototypen

int fileHandling(vector<string> &stringVec, char *fileName, int mode);
void tableFunc();

int inlineEdit(vector<string> &stringVec, char *iFile, int mode, int newFile);
void changeLine(vector<string> &stringVec, string newString, unsigned int aktLine);
int insertLine(vector<string> &stringVec, vector<string>::iterator &it, string newString, unsigned int aktLine, int newFile);
int deleteLine(vector<string> &stringVec, vector<string>::iterator &it, unsigned int aktLine);
int searchString(vector<string> &stringVec, vector<string>::iterator &it, string newString, unsigned int aktLine);

int main()
{
	char key;
	int mode=0; // 0=open, 1=save
	char fileName[42];

    	vector<string> stringVec;
	
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
			case 'o':	mode = 0;
					cout << endl << "Dateinamen eingeben" << endl;
    					cout << "> ";
       					cin.ignore();
        				cin >> fileName;	
					fileHandling(stringVec, fileName, mode);
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

int fileHandling(vector<string> &stringVec, char *fileName, int mode)
{
    string null=""; 
    string buffer;
    char choice;
    string enter;
    int newFile = 0;
 
    ifstream iFile;
    ofstream oFile;
    
    if(mode == 0){                  //Öffnen
        
        iFile.open(fileName);
        
        if(!iFile){
            cout << endl << "Datei existiert nicht !" << endl;
            cout << " Diese Datei erzeugen? (y/n)" << endl << "> ";
            cin.ignore();
            cin.get(choice);
            
            if (choice == 'y'){
		stringVec.push_back(null);
	        newFile = 1;	
	    }else if(choice == 'n'){
                return 0;
            }
        }

        
        while(getline(iFile, buffer)){
            
            stringVec.push_back(buffer);
        
        }
        
        iFile.close();
        
        inlineEdit(stringVec, fileName, mode, newFile);
        
    }else if(mode == 1){            //Speichern
    
        oFile.open(fileName);
    
        for (it = stringVec.begin(); it != stringVec.end(); ++it){
        
            oFile << *it << endl;
        }
        
        oFile.close();
       
	it = stringVec.begin(); 
        system("clear");
	cout << "Datei " << fileName << "geschreiben" << endl;
        
	cout << "\nSuchstring nicht gefunden - Press Return to continue\n";
	getline(cin, enter);
    }	
    return 0;
}

int inlineEdit(vector<string> &stringVec, char *fileName, int mode, int newFile)
{   
	char key;
	unsigned int aktLine = 1;
	string newString;
	string anyKey;

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
              		
			case 'a':	cout << "\nNeue Zeile einfügen\n>";
                                        cin.ignore();
                                        getline(cin, newString);

					changeLine(stringVec, newString, aktLine);
					break;

			case 'e':	cout << "\nNeue Zeile einfügen\n>";
					cin.ignore();
					getline(cin, newString);
					aktLine = insertLine(stringVec, it, newString, aktLine, newFile);
					break;	

			case 'l':	aktLine = deleteLine(stringVec, it, aktLine);
					
					break;
		
			case 'u':	cout << "\nSuchstring eingeben\n>";
                                        cin.ignore();
                                        getline(cin, newString);
					aktLine = searchString(stringVec, it, newString, aktLine);
					if (aktLine == 4711){
						cout << "\nSuchstring nicht gefunden - Press Return to continue\n";
						getline(cin, anyKey);
						aktLine = 1;
					}
					break;												
        
			case 's':	mode = 1;	 //speichermodus aktivieren
					fileHandling(stringVec, fileName, mode);
					return 0;												

		      	case 'b':	return 0;
	
			default:	cout << "Falsche Eingabe";
		}
	}while(key != 'q');
	
	return 0;
}



int insertLine(vector<string> &stringVec, vector<string>::iterator &it, string newString, unsigned int aktLine, int newFile)
{
	if(newFile == 1){
		stringVec.push_back(newString);
		aktLine++;
		return aktLine;
	}
	++it;		//damit nach der aktuellen Zeile der newString eingefügt wird	
	stringVec.insert(it, newString);
	aktLine++;
	return aktLine;	
}


int deleteLine(vector<string> &stringVec, vector<string>::iterator &it, unsigned int aktLine)
{
	stringVec.erase(it);
	if(aktLine == stringVec.size()){
		aktLine--;
		--it;
		it = stringVec.end();
	}

	return aktLine;
}


void changeLine(vector<string> &stringVec, string newString, unsigned int aktLine)
{
	stringVec[aktLine-1] = newString;
}


int searchString(vector<string> &stringVec, vector<string>::iterator &it, string newString, unsigned int aktLine)
{
	system("clear");
	aktLine = 1;
	string buffer;

	for (it = stringVec.begin(); it != stringVec.end(); ++it){
		buffer = *it;
		if(buffer.find(newString) != -1){
			return aktLine;
		}else{
			aktLine++;
		}
	}
	it = stringVec.begin();
	aktLine = 4711;
	return aktLine;
}
