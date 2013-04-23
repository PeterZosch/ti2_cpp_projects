#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){

	int a,b;

	cout << "Zahl eingeben:\n";

//	setvbuf( stdin, NULL, _IONBF, 0 );
//	setvbuf( stdin, NULL, _IOFBF, BUFSIZ ); 
	rewind(stdin);

	cin >> a;

	cout << "Zahl eingeben:\n";
//	setvbuf( stdin, NULL, _IONBF, 0 );
//	setvbuf( stdin, NULL, _IOFBF, BUFSIZ ); 
	rewind(stdin);
	cin >> b;
	cout << "\na=" << a <<"\nb=" << b;


	return 0;

}
