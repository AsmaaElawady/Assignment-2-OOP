#ifndef UNTITLED1_BIGDECINT_H
#define UNTITLED1_BIGDECINT_H

#include <bits/stdc++.h>

using namespace std;

class BigDecimalInt{
private:
    vector <int> vec;
    char s; // for the sign.
public:
    // constructor
    BigDecimalInt (){}
    void setVec (vector <int> v);
    vector<int> getVector ();
    void setS(char sign);
    char getS();
    BigDecimalInt (int decInt);
    BigDecimalInt (string decStr);
    // function to check the size of the two numbers and make thim equal.
    void checkSize(vector <int>& v1,vector <int>& v2);
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt b) ;
    bool operator< (BigDecimalInt b);
    bool operator== (BigDecimalInt b);
    bool operator= (BigDecimalInt b);
    int size();
    char sign();
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    friend ostream& operator<< (ostream& out, BigDecimalInt a);

    void subtraction(vector <int>& v1,vector <int>& v2);
    void addition(vector <int>& v1,vector <int>& v2);
    void zeros(vector <int>& v1);


};
