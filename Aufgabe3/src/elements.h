#include <vector>

class Elements
{

public:

	double value;
	std::vector<double> amp, volt;
	
	virtual void Set_Value( double newValue );
 
	virtual void Set_Voltage( double newVolt )  { volt.push_back( newVolt ); }	
	virtual void Set_Ampere( double newAmp )    { amp.push_back( newAmp ); }	

	virtual double Get_Value(void)   { return value; }
	virtual double Get_Voltage() { return volt.at( volt.size() - 1 ); }
	virtual double Get_Ampere()  { return amp.at( amp.size() - 1 ); }

	virtual void Reset() { volt.clear(); amp.clear(); }

    typedef std::vector<double>::iterator iterator;
    iterator beginA() { return amp.begin(); };
    iterator endA() { return amp.end(); };
    iterator beginV() { return volt.begin(); };
    iterator endV() { return volt.end(); };

}; 

