/*
 Andrew Dante Ausonio
 5/23/22
 Dave Harden
 cs_fraction.hpp
 A2_1
 
 
 This class allows you to make use of fraction objects. It can input and output fraction values, It simplifies values, and allows you to perform a series of mathematical operations using fractions. It even overloads operators to make your code more elegant.
 
 
 Prototype List:
 Fraction(int inNum = 0, int inDenom = 1);
    postcondition: Constructor that initializes a fraction object.
 void Simplify();
    postcondition: Simplifies a fraction, and turns it into a whole or mixed number if needed.
 friend ostream& operator<<(ostream& out,const Fraction& right);
    postcondition: tunrs fraction into an output stream.
 friend istream& operator>>(istream& in, Fraction& right);
    postcondition: uses input stream to initialize a fraction object.
 friend bool operator<(const Fraction& left, const Fraction& right);
    postcondition: ture or false comparison statement
 friend bool operator<=(const Fraction& left, const Fraction& right);
    postcondition: ture or false comparison statement
 friend bool operator>(const Fraction& left, const Fraction& right);
    postcondition: ture or false comparison statement
 friend bool operator>=(const Fraction& left, const Fraction& right);
    postcondition: ture or false comparison statement
 friend bool operator!=(const Fraction& left, const Fraction& right);
    postcondition: ture or false comparison statement
 friend bool operator==(const Fraction& left, const Fraction& right);
    postcondition: ture or false comparison statement
 friend Fraction operator+(const Fraction& left, const Fraction& right);
    postcondition: returns fraction that is sum of two input fractions.
 friend Fraction operator-(const Fraction& left, const Fraction& right);
    postcondition: returns fraction that is difference of two input fractions.
 friend Fraction operator*(const Fraction& left, const Fraction& right);
    postcondition: returns fraction that is product of two input fractions.
 friend Fraction operator/(const Fraction& left, const Fraction& right);
    postcondition: returns fraction that is quotient of two input fractions.
 Fraction operator+=(const Fraction& right);
    postcondition: Adds value on the right to the fraction on the left
 Fraction operator-=(const Fraction& right);
    postcondition: Subtracts value on the right to the fraction on the left
 Fraction operator*=(const Fraction& right);
    postcondition: Multiplies value on the right to the fraction on the left
 Fraction operator/=(const Fraction& right);
    postcondition: Divides value on the right to the fraction on the left
 Fraction operator++();
    postcondition: postincriment operator for fraction type objects
 Fraction operator++(int);
    postcondition: preincriment operator for fraction type objects
 Fraction operator--();
    postcondition: postdecrement operator for fraction type objects
 Fraction operator--(int);
    postcondition: predecrement operator for fraction type objects
*/

#ifndef fraction_h
#define fraction_h

#include <stdio.h>
#include <iostream>

#include <string>
#include <cassert>
#include <fstream>
using namespace std;

namespace cs_fraction {

class Fraction
{
    
public:
    Fraction(int inNum = 0, int inDenom = 1);
    void Simplify();
        friend ostream& operator<<(ostream& out,const Fraction& right);
        friend istream& operator>>(istream& in, Fraction& right);
        friend bool operator<(const Fraction& left, const Fraction& right);
        friend bool operator<=(const Fraction& left, const Fraction& right);
        friend bool operator>(const Fraction& left, const Fraction& right);
        friend bool operator>=(const Fraction& left, const Fraction& right);
        friend bool operator!=(const Fraction& left, const Fraction& right);
        friend bool operator==(const Fraction& left, const Fraction& right);
        friend Fraction operator+(const Fraction& left, const Fraction& right);
        friend Fraction operator-(const Fraction& left, const Fraction& right);
        friend Fraction operator*(const Fraction& left, const Fraction& right);
        friend Fraction operator/(const Fraction& left, const Fraction& right);
    Fraction operator+=(const Fraction& right);
    Fraction operator-=(const Fraction& right);
    Fraction operator*=(const Fraction& right);
    Fraction operator/=(const Fraction& right);
    Fraction operator++();
    Fraction operator++(int);
    Fraction operator--();
    Fraction operator--(int);
    
    
private:
    int num;
    int denom;
};
}
#endif /* cs_fraction_h */
