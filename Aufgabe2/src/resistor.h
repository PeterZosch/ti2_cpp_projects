#include <vector>

class Resistor
{
	double valueR;

	std::vector<double> amp_R, volt_R;

public:

	void Set_Value( double newValue );
 
	void Set_Voltage( double newVolt )  { volt_R.push_back( newVolt ); }	
	void Set_Ampere( double newAmp )    { amp_R.push_back( newAmp ); }	

	double Get_Value(void)   { return valueR; }
	double Get_Voltage() { return volt_R.at( volt_R.size() - 1 ); }
	double Get_Ampere()  { return amp_R.at( amp_R.size() - 1 ); }

	void Reset() { volt_R.clear(); amp_R.clear(); }

    typedef std::vector<double>::iterator iterator;
    iterator beginA() { return amp_R.begin(); };
    iterator endA() { return amp_R.end(); };
    iterator beginV() { return volt_R.begin(); };
    iterator endV() { return volt_R.end(); };

}; 

