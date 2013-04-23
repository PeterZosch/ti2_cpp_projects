#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

//Funktionsprototypen

void fileHandling(int mode);
void tableFunc();

void inlineEdit(vector<string> &stringVec, int linecount, char *iFile);
void changeLine();
void insertLine();
void deleteLine();
void searchString();

int main()
{
	int mode = 0;
    char key;
	do{
		system("clear");

		cout << endl << "Hautpmenue";
		cout << endl << "----------";
		cout << endl <<	"(o) Datei oeffnen";
		cout << endl << "(t) Tabellenfunktion";
		cout << endl << "(q) Quit";
		
		cout << endl << (">");
		cin.sync();
		cin >> key;

		switch(key){
			case 'o'://	cout << "fileHandling(int mode)";
                    fileHandling(mode);
					break;
			
			case 't':	cout << "tableFunc()";
					break;

			case 'q':	return 0;
			
			default :	cout << "\tFalsche Eingabe";
//					nanosleep(1000);
		}
	}while(key != 'q');

	return 0;
}

void fileHandling(int mode){
    
    int lineCnt = 0;
    
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
            cout << " Neue Datei erzeugen? (y/n)" << endl << "> ";
            cin.ignore();
            cin.get(choice);
            
            if (choice == 'y'){
                cout << "Dateinnamen der neuen Datei eingeben" << endl << "> ";
                cin.ignore();
                cin >> fileName;
            }else if(choice == 'n'){
                EXIT_SUCCESS;
            }
        }

        
        while(getline(iFile, buffer)){
            
            lineCnt++;
            stringVec.push_back(buffer);
        
        }
        
        iFile.close();
        
        inlineEdit(stringVec, lineCnt, fileName);
        
    }else if(mode == 1){            //Speichern
    
        oFile.open(fileName);
    
        for (vector<string>::iterator it = stringVec.begin(); it != stringVec.end(); ++it){
        
            oFile << *it;
        }
        
        oFile.close();
        
        cout << "Datei " << fileName << "geschreiben" << endl;
        
    }
}