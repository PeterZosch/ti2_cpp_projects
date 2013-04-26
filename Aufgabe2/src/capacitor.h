#include <vector>

class Capacitor
{
	double valueC;

	std::vector<double> amp_C, volt_C;

public:
	
	void Set_Value( double newValue );
 
	void Set_Voltage( double newVolt )  { volt_C.push_back( newVolt ); }	
	void Set_Ampere( double newAmp )    { amp_C.push_back( newAmp ); }	

	double Get_Value(void)   { return valueC; }
	double Get_Voltage() { return volt_C.at( volt_C.size() - 1 ); }
	double Get_Ampere()  { return amp_C.at( amp_C.size() - 1 ); }

	void Reset() { volt_C.clear(); amp_C.clear(); }

	typedef std::vector<double>::iterator iterator;
	iterator beginA() { return amp_C.begin(); };
	iterator endA() { return amp_C.end(); };
	iterator beginV() { return volt_C.begin(); };
	iterator endV() { return volt_C.end(); };
};

