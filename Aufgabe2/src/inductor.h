#include <vector>

class Inductor
{
	double valueL;

	std::vector<double> amp_L, volt_L;

public:
	
	void Push_Value( double newValue ) { valueL = newValue; }
	void Push_Voltage( double newVolt )  { volt_L.push_back( newVolt ); }	
	void Push_Ampere( double newAmp )    { amp_L.push_back( newAmp ); }	

	double Pull_Value(void)   { return valueL; }
	double Pull_Voltage() { return volt_L.at( volt_L.size() - 1 ); }
	double Pull_Ampere()  { return amp_L.at( amp_L.size() - 1 ); }

	void Reset() { volt_L.clear(); amp_L.clear(); }
};
