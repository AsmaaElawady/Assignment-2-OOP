#ifndef BIGREAL_H_INCLUDED
#define BIGREAL_H_INCLUDED
#include <iostream>
using namespace std;
class BigReal
{
private:
    string number;
    BigDecimalInt str;
    char signn;
    void setNumber(string num);
    bool checkValidInput(string input);
public:
    BigReal (double realNumber = 0.0); // Default constructor
    BigReal (string realNumber);
    BigReal (BigDecimalInt bigInteger);
    BigReal (const BigReal& other); // Copy constructor
    BigReal (BigReal&& other); // Move constructor
    BigReal& operator= (BigReal& other); // Assignment operator
    BigReal& operator= (BigReal&& other); // Move assignment
    BigReal operator+ (BigReal other);
    BigReal operator- (BigReal other);
    bool operator== (BigReal other);
    bool operator< (BigReal other);
    bool operator> (BigReal other);
    int  Nsign();
    int size();
    friend ostream& operator<< (ostream& out, BigReal other);

};


#endif // BIGREAL_H_INCLUDED
