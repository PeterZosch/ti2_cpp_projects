#include <vector>

class Capacitor
{
	double valueC;

	std::vector<double> amp_C, volt_C;

public:
	
	void Push_Value( double newValue ) { valueC = newValue; }
	void Push_Voltage( double newVolt )  { volt_C.push_back( newVolt ); }	
	void Push_Ampere( double newAmp )    { amp_C.push_back( newAmp ); }	

	double Pull_Value(void)   { return valueC; }
	double Pull_Voltage() { return volt_C.at( volt_C.size() - 1 ); }
	double Pull_Ampere()  { return amp_C.at( amp_C.size() - 1 ); }

	void Reset() { volt_C.clear(); amp_C.clear(); }
};

