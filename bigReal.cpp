#include"BigReal.h"
#include"../BigDecimalIntClass.h"
bool BigReal::checkInput(string input)
{
    if (input == ".")
        return false;
    regex validInput("[-+]?[0-9]+.[0-9]+");
    return regex_match(input, validInput);
}


bool BigReal::checkValidInput(string input)
{
    if (input[0] == '-' || input[0] == '+')
    {
        // input.erase(0,1);
    }
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            return false;
        }
    }
    return true;
}


//Default constructor
BigReal::BigReal (double realNumber)
{
    number = to_string(realNumber);
}

BigReal::BigReal (string realNumber)
{
    number = realNumber;

    bool validNumber = checkInput(realNumber);
    if (validNumber)
    {
        // sign = number[0];
        if (number[0] == '-')
        {
            signn = '-';
            //  number.erase(0,1);
        }
        else if (number[0] == '+')
        {
            signn = '+';
            //   number.erase(0,1);
        }
        else
        {
            signn = '+';
        }
        //  number = num;
    }
    else
    {
      //  cout << "Invalid Real Number" <<endl;
    }

}

BigReal::BigReal (BigDecimalInt bigInteger)
{
    str=bigInteger.getNumber();
}

//Copy constructor
BigReal::BigReal (const BigReal& other)
{
    number = other.number;

}

// Move constructor
BigReal::BigReal (BigReal&& other)
{
    this -> number = other.number;
}

// Assignment operator
BigReal& BigReal::operator= (BigReal& other)
{
    number = other.number;

}

//Move assignment
BigReal& BigReal::operator= (BigReal&& other)
{
    this -> number = other.number;
    return *this;
}

ostream &operator << (ostream &out, BigReal num)
{
  //  out<< (char) num.signn;
 out<< num.number;

    return out;
}
istream &operator>> (istream& in, BigReal& other)
 {
  //  string numb;
    in>> other.number;
    return in  ;
 }
bool BigReal:: operator< (BigReal anotherReal)
{

    int index;
    string temp;
    if(!number.find('.'))
    {
       number = number+ ".0";
    }
    ///////////FIRST NUMBER LOADING///////////
    for(int i = 0; i<number.size(); i++)
    {
        if(number[i] == '.')
        {
            index = i;
        }
    }

    for(int i =0; i<index ; i++)
    {
        temp+= number[i];
    }
    BigDecimalInt num1I(temp) ; // the integer part in the first number is done
    temp="";
    for(int i =index+1; i<number.size() ; i++)
    {
        temp+= number[i];
    }
    BigDecimalInt num1f(temp); // the fraction part in the first number is done
//////////SECOND NUMBER LOADING////////////
    temp="";
     if(!anotherReal.number.find('.'))
    {
        anotherReal.number = anotherReal.number+ ".0";
    }
    for(int i = 0; i<anotherReal.number.size(); i++)
    {
        if(anotherReal.number[i] == '.')
        {
            index = i;
        }
    }

    for(int i =0; i<index ; i++)
    {
        temp+= anotherReal.number[i];
    }
    BigDecimalInt num2I(temp) ; // the integer part in the first number is done
    temp="";
    for(int i =index+1; i<anotherReal.number.size() ; i++)
    {
        temp+= anotherReal.number[i];
    }
    BigDecimalInt num2f(temp);
 //   cout<< num1I<< num1f << num2I << num2f;
////////////////////////////////////////////
    if(num1I > num2I)
    {
        return false;   // 5.3 4.3// 5.3 -5.3// -4.3 -5.3
    }
    else if(num2I > num1I)
    {
        return true;   // 4.3 5.3 // -5.3 -4.3 //-5.3 5.3// -4.3 5.3
    }
    else if(num1I == num2I)
    {
      /*  if(num1f.size() > num2f.size())
        {
            int tempp = num1f.size()  - num2f.size();
            for(int i = 0; i < tempp; i++) num2f.getNumber() = num2f.setNumber() + "0";
        }
        else  if(num1f.size() <num2f.size())
        {
            int tempp = num2f.size()  - num1f.size();
            for(int i = 0; i < tempp; i++) num1f.getNumber() = num1f.setNumber() + "0";
        }*/
        if(Nsign() == -1)
        {
            if(num1f> num2f)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(num1f> num2f)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

    }

}
bool BigReal:: operator > (BigReal anotherReal)
{
//cout<< Nsign();
//cout<< anotherReal.Nsign();
    int index;
    string temp;
     if(!number.find('.'))
    {
        number = number+ ".0";
    }
    ///////////FIRST NUMBER LOADING///////////
    for(int i = 0; i<number.size(); i++)
    {
        if(number[i] == '.')
        {
            index = i;
        }
    }

    for(int i =0; i<index ; i++)
    {
        temp+= number[i];
    }
    BigDecimalInt num1I(temp) ; // the integer part in the first number is done
    temp="";
    for(int i =index+1; i<number.size() ; i++)
    {
        temp+= number[i];
    }
    BigDecimalInt num1f(temp); // the fraction part in the first number is done
//////////SECOND NUMBER LOADING////////////
    temp="";
     if(!anotherReal.number.find('.'))
    {
        anotherReal.number = anotherReal.number+ ".0";
    }
    for(int i = 0; i<anotherReal.number.size(); i++)
    {
        if(anotherReal.number[i] == '.')
        {
            index = i;
        }
    }

    for(int i =0; i<index ; i++)
    {
        temp+= anotherReal.number[i];
    }
    BigDecimalInt num2I(temp) ; // the integer part in the first number is done
    temp="";
    for(int i =index+1; i<anotherReal.number.size() ; i++)
    {
        temp+= anotherReal.number[i];
    }
    BigDecimalInt num2f(temp);
  //  cout<< num1I<< num1f<< num2I<< num2f;
////////////////////////////////////////////
    if(num1I > num2I)
    {cout<< "g";
        return true;   // 5.3 4.3// 5.3 -5.3// -4.3 -5.3
    }
    else if(num2I > num1I)
    {
        return false;   // 4.3 5.3 // -5.3 -4.3 //-5.3 5.3// -4.3 5.3
    }
    else if(num1I == num2I)
    {
        if(Nsign() == -1)
        {
            if(num1f> num2f)
            {cout<< "k";
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            if(num1f> num2f)
            {
                cout<< "f";
                return true;
            }
            else
            {
                return false;
            }
        }

    }

}

int BigReal:: Nsign()
{
    if(signn == '-')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
int BigReal ::size()
{
    return number.size()-1;
}
/////////////////////////////////////////////////
bool BigReal:: operator== (BigReal anotherReal)
{
    int index;
    string temp = "";
    ///////////FIRST NUMBER LOADING///////////
    if(!number.find('.'))
    {
        number = number+ ".0";
    }
    for(int i = 0; i<number.size(); i++)
    {
        if(number[i] == '.')
        {
            index = i;
            //  cout << index;
        }
    }

    for(int i =0; i<index ; i++)
    {
        temp+= number[i];
        //  cout<< temp;
    }
    BigDecimalInt num1I(temp) ; // the integer part in the first number is done
    // cout<< num1I;
    string tempn2="";
    for(int i =index+1; i<number.size() ; i++)
    {
        tempn2+= number[i];
    }

    BigDecimalInt num1f(tempn2); // the fraction part in the first number is done
    //  cout<< num1f;

//////////SECOND NUMBER LOADING////////////
    int index2;
    string tempn1="";
    if(!anotherReal.number.find('.'))
    {
        anotherReal.number = anotherReal.number+ ".0";
    }
    for(int i = 0; i<anotherReal.number.size(); i++)
    {
        if(anotherReal.number[i] == '.')
        {
            index2 = i;
        }
    }

    for(int i =0; i<index2 ; i++)
    {
        tempn1+= anotherReal.number[i];
    }
    BigDecimalInt num2I(tempn1) ; // the integer part in the first number is done
    // cout<< num2I;


    string tempf = "";
    for(int i =index2+1; i<anotherReal.number.size() ; i++)
    {
        tempf+= anotherReal.number[i];
        //   cout<< temp;
    }


    BigDecimalInt num2f(tempf); // the fraction part in the first number is done
    //    cout<< num2f;

////////////////////////////////////////////
    if((num1f == num2f) && (num1I == num2I))
    {
        return true;
    }

    else
    {
        return false;
    }

}
