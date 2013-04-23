#include <vector>

class Resistor
{
	double valueR;

	std::vector<double> amp_R, volt_R;

public:

	void Push_Value( double newValue ) { valueR = newValue; }
	void Push_Voltage( double newVolt )  { volt_R.push_back( newVolt ); }	
	void Push_Ampere( double newAmp )    { amp_R.push_back( newAmp ); }	

	double Pull_Value(void)   { return valueR; }
	double Pull_Voltage() { return volt_R.at( volt_R.size() - 1 ); }
	double Pull_Ampere()  { return amp_R.at( amp_R.size() - 1 ); }

	void Reset() { volt_R.clear(); amp_R.clear(); }
}; 

