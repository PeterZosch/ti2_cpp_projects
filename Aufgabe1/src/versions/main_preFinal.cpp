#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

vector<string>::iterator it;

//Funktionsprototypen

int fileHandling(vector<string> &stringVec, char *fileName, int mode);
int tableFunc(char *dname);

int inlineEdit(vector<string> &stringVec, char *iFile, int mode, int newFile);
void changeLine(vector<string> &stringVec, string newString, unsigned int aktLine);
int insertLine(vector<string> &stringVec, vector<string>::iterator &it, string newString, unsigned int aktLine, int newFile);
int deleteLine(vector<string> &stringVec, vector<string>::iterator &it, unsigned int aktLine);
int searchString(vector<string> &stringVec, vector<string>::iterator &it, string newString, unsigned int aktLine);

void eraseBuffer();


int main()
{
	char key;
	int mode=0; // 0=open, 1=save
	char fileName[42];
	char dname[42];

    	vector<string> stringVec;
	
	do{
		system("clear");

		cout << endl << "Hautpmenue";
		cout << endl << "----------";
		cout << endl <<	"(o) Datei oeffnen";
		cout << endl << "(t) Tabellenfunktion";
		cout << endl << "(q) Quit";
		
		cout << endl << (">");
		void eraseBuffer();
		cin.get(key);
		cin.ignore();
		void eraseBuffer();

		switch(key){
			case 'o':	mode = 0;
					cout << endl << "Dateinamen eingeben" << endl;
    					cout << "> ";
					void eraseBuffer();
        				cin >> fileName;	
					void eraseBuffer();
					fileHandling(stringVec, fileName, mode);
					break;
			
			case 't':      	cout << "\nDateinamen eingeben" << endl << "> "; 
					void eraseBuffer();
   					cin >> dname;
					void eraseBuffer();
					tableFunc(dname);
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
	    
	    void eraseBuffer();
	    cin.get(choice);            
            cin.ignore();
	    void eraseBuffer();
            
            if (choice == 'y'){
		stringVec.push_back(null);
	        newFile = 1;
		iFile.close();
        	inlineEdit(stringVec, fileName, mode, newFile);
	
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
        
	void eraseBuffer();
	cout << "\nSuchstring nicht gefunden - Press Return to continue\n";
	getline(cin, enter);
	void eraseBuffer();

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
           	
		void eraseBuffer();
		cin.get(key);
		cin.ignore();
		void eraseBuffer();
		
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
					void eraseBuffer();
                                        getline(cin, newString);
					void eraseBuffer();
					changeLine(stringVec, newString, aktLine);
					break;

			case 'e':	cout << "\nNeue Zeile einfügen\n>";
					void eraseBuffer();
					getline(cin, newString);
					void eraseBuffer();
					aktLine = insertLine(stringVec, it, newString, aktLine, newFile);
					break;	

			case 'l':	aktLine = deleteLine(stringVec, it, aktLine);
					
					break;
		
			case 'u':	cout << "\nSuchstring eingeben\n>";
					void eraseBuffer();
                                        getline(cin, newString);
					void eraseBuffer();
					aktLine = searchString(stringVec, it, newString, aktLine);
					if (aktLine == 4711){
						cout << "\nSuchstring nicht gefunden - Press Return to continue\n";
						void eraseBuffer();
						getline(cin, anyKey);
						void eraseBuffer();
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

int tableFunc(char *dname)
{
    system("clear"); 
    float amt, mean, vrne, zahl, temp, sum;
    amt = mean = vrne = zahl = temp = sum = 0;	 
    string buffer, zosh;
    
    
    ifstream tfile;
    tfile.open(dname);
    
    vector<int> numList;
    
    while(getline(tfile, buffer)){
        
        zahl = atoi(buffer.c_str());
        numList.push_back(zahl);
    }
    
    amt = numList.size();
    cout << "Zahlen der Datei:\n";
	 
    for (vector<int>::iterator it1 = numList.begin(); it1 != numList.end(); ++it1){
        cout << " " << *it1;
        sum += *it1;
    }
    cout << endl << "Summe ist : " << sum;
    
    amt = numList.size();
    mean = sum / amt;
    cout << endl << "Mittelwert ist : " << mean;
    
    for (vector<int>::iterator it1 = numList.begin(); it1 != numList.end(); ++it1){
        temp += pow((*it1 - mean), 2) ;
    }
    
    vrne = temp / amt;
    cout << endl << "Varianz ist : " << vrne << endl;
    
    cout << "\n\n\nplease press Return to continue" << endl;
    void eraseBuffer();
    getline(cin, zosh);
    void eraseBuffer();
    
    return 0; 
}

void eraseBuffer()
{
        setvbuf( stdin, NULL, _IONBF, 0 );
        setvbuf( stdin, NULL, _IOFBF, BUFSIZ );
}
