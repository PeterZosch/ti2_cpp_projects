#include <vector>

class Inductor
{
	double valueL;

	std::vector<double> amp_L, volt_L;

public:
	
	void Set_Value( double newValue ) { valueL = newValue; }
	void Set_Voltage( double newVolt )  { volt_L.push_back( newVolt ); }	
	void Set_Ampere( double newAmp )    { amp_L.push_back( newAmp ); }	

	double Get_Value(void)   { return valueL; }
	double Get_Voltage() { return volt_L.at( volt_L.size() - 1 ); }
	double Get_Ampere()  { return amp_L.at( amp_L.size() - 1 ); }

	void Reset() { volt_L.clear(); amp_L.clear(); }
};
