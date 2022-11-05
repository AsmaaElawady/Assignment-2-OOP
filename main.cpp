//#include <iostream>
#include"bigReal.h"
#include"../BigDecimalIntClass.h"

using namespace std;

int main() {
BigReal b1 ("11.12");
BigReal b2 ("11.20");
// if the two int are equal
// if the size of the fractions are not equal
// fill the smaller one with zeros and flip it to compare
// 12 , 02-> 20
if(b1<b2)
{
    cout<< "True";
}
else
    {cout<< "False";}

//cout<< b1.Nsign();
//cout<< b2.Nsign();
//cout<< b1.size();



}













