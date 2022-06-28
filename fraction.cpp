/*
 2 Data Members:
 Num acts as the numerator of the fraction.
 Denom acts as the denominator of the fraction.
 
 
 Fraction objects will always be stored in lowest terms.
 Fraction objects will be stored in improper form and only converted to mixed fractions when printing.
 The Denominator will never be negative. Any negatives will be stored in the numerator, or in the case of a mixed fraction the sign will be assined to the whole number before the fraction.
 
*/

#include "fraction.h"
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
using namespace std;



namespace cs_fraction {


Fraction::Fraction(int inNum, int inDenom)
{
    assert(inDenom != 0);
    num = inNum;
    denom = inDenom;
    Simplify();
}






void Fraction::Simplify()
{
    if (denom < 0){
        denom *= -1;
        num *= -1;
    }
    
    for (int i = denom; i > 1; i--){
        if (num % i == 0 && denom % i == 0){
            num /= i;
            denom /= i;
        }
    }
    
    if (num == 0){
        denom = 1;
    }
}





/*
 This function takes an input stream and converts it into a fraction object by abstracting its numerator and denominator based weather its a mixed fraction or not using the extraction operator. in represents the input streeam, and right is the fraction object.
 */
istream& operator>>(istream& in, Fraction& right)
{
    int temp;
    in >> temp;
    if (in.peek() == '+'){
        int wholeNum = temp;
        in.ignore();
        in >> temp;
        if (in.peek() == '/'){
            right.num = temp;
            in.ignore();
            in >> temp;
            right.denom = temp;
            temp = right.num;
            if (wholeNum > 0){
                right.num = (right.denom * wholeNum) + temp;
            } else if (wholeNum < 0){
                right.num = (right.denom * wholeNum) - temp;
            }
        }
    } else if (in.peek() == '/'){
        right.num = temp;
        in.ignore();
        in >> temp;
        right.denom = temp;
    } else {
        right.num = temp;
        right.denom = 1;
    }
    right.Simplify();
    return in;
}






/*
 This function allows you to convert a fraction object into an output stream using the insertion operator. out is a stream that displays a fraction in mixed, proper or improper form. Right is the fraction object whose numerator and denominator are being displayed.
 */
ostream& operator<<(ostream& out, const Fraction& right)
{
    int WholeNumber;
    int Remainder;
    
    WholeNumber = right.num / right.denom;
    Remainder = right.num - (right.denom * WholeNumber);
    
    if (right.denom == 1){
        out << right.num;
    } else if (WholeNumber == 0) {
        out << right.num << "/" << right.denom;
    } else {
        if (Remainder < 0)
        {
            Remainder *= -1;
        }
        out << WholeNumber << "+" << Remainder << "/" << right.denom;
    }
    
    return out;
}






bool operator<(const Fraction& left, const Fraction& right)
{
    int l = left.num * right.denom;
    int r = right.num * left.denom;
    
    if (l < r){
        return true;
    }
    if (l > r){
        return false;
    }
    return l < r;
}






bool operator<=(const Fraction& left, const Fraction& right)
{
    int l = left.num * right.denom;
    int r = right.num * left.denom;
    
    if (l <= r){
        return true;
    }
    if (l >= r){
        return false;
    }
    return l < r;
}






bool operator>(const Fraction& left, const Fraction& right)
{
    int l = left.num * right.denom;
    int r = right.num * left.denom;
    
    if (l > r){
        return true;
    }
    if (l < r){
        return false;
    }
    return l > r;
}






bool operator>=(const Fraction& left, const Fraction& right)
{
    int l = left.num * right.denom;
    int r = right.num * left.denom;
    
    if (l >= r){
        return true;
    }
    if (l <= r){
        return false;
    }
    return l >= r;
}






bool operator!=(const Fraction& left, const Fraction& right)
{
    int l = left.num * right.denom;
    int r = right.num * left.denom;
    
    if (l != r){
        return true;
    }
    if (l == r){
        return false;
    }
    return l != r;
}






bool operator==(const Fraction& left, const Fraction& right)
{
    int l = left.num * right.denom;
    int r = right.num * left.denom;
    
    if (l == r){
        return true;
    }
    if (l != r){
        return false;
    }
    return l == r;
}






Fraction operator+(const Fraction& left, const Fraction& right)
{
    Fraction result;
    result.num = (left.num * right.denom) + (right.num * left.denom);
    result.denom = (left.denom * right.denom);
    result.Simplify();
    return result;
}






Fraction operator-(const Fraction& left, const Fraction& right)
{
    Fraction result;
    result.num = (left.num * right.denom) - (right.num * left.denom);
    result.denom = (left.denom * right.denom);
    result.Simplify();
    return result;
}






Fraction operator*(const Fraction& left, const Fraction& right)
{
    Fraction result;
    result.num = left.num * right.num;
    result.denom = left.denom * right.denom;
    result.Simplify();
    return result;
}






Fraction operator/(const Fraction& left, const Fraction& right)
{
    Fraction result;
    result.num = left.num * right.denom;
    result.denom = left.denom * right.num;
    result.Simplify();
    return result;
}






Fraction Fraction::operator+=(const Fraction& right)
{
    *this = *this + right;
    return *this;
}






Fraction Fraction::operator-=(const Fraction& right)
{
    *this = *this - right;
    return *this;
}






Fraction Fraction::operator*=(const Fraction& right)
{
    *this = *this * right;
    return *this;
}






Fraction Fraction::operator/=(const Fraction& right)
{
    *this = *this / right;
    return *this;
}






Fraction Fraction::operator++()
{
    num += denom;
    return *this;
}






Fraction Fraction::operator++(int)
{
    Fraction temp(num, denom);
    num += denom;
    return temp;
}






Fraction Fraction::operator--()
{
    num -= denom;
    return *this;
}






Fraction Fraction::operator--(int)
{
    Fraction temp(num, denom);
    num -= denom;
    return temp;
}
}


/* OUTPUT:
 ----- Testing basic Fraction creation & printing
 (Fractions should be in reduced form, and as mixed numbers.)
 Fraction [0] = 1/2
 Fraction [1] = -5/7
 Fraction [2] = 10
 Fraction [3] = -4
 Fraction [4] = 0
 Fraction [5] = 4+2/3
 Fraction [6] = 0

 ----- Now reading Fractions from file
 Read Fraction = 1/3
 Read Fraction = 1/2
 Read Fraction = 3/4
 Read Fraction = -4/5
 Read Fraction = 6
 Read Fraction = 5
 Read Fraction = -8
 Read Fraction = 1+2/5
 Read Fraction = -16+2/3
 Read Fraction = 1+1/4
 Read Fraction = 2
 Read Fraction = -4+1/4
 Read Fraction = -10+5/6

 ----- Testing relational operators between Fractions
 Comparing 1/2 to -1/2
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing -1/2 to 1/2
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing 1/2 to 1/10
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing 1/10 to 0
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing 0 to 0
     Is left < right? false
     Is left <= right? true
     Is left > right? false
     Is left >= right? true
     Does left == right? true
     Does left != right ? false

 ----- Testing relations between Fractions and integers
 Comparing -1/2 to 2
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing -3 to 1/4
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true

 ----- Testing binary arithmetic between Fractions
 1/6 + 1/3 = 1/2
 1/6 - 1/3 = -1/6
 1/6 * 1/3 = 1/18
 1/6 / 1/3 = 1/2
 1/3 + -2/3 = -1/3
 1/3 - -2/3 = 1
 1/3 * -2/3 = -2/9
 1/3 / -2/3 = -1/2
 -2/3 + 5 = 4+1/3
 -2/3 - 5 = -5+2/3
 -2/3 * 5 = -3+1/3
 -2/3 / 5 = -2/15
 5 + -1+1/3 = 3+2/3
 5 - -1+1/3 = 6+1/3
 5 * -1+1/3 = -6+2/3
 5 / -1+1/3 = -3+3/4

 ----- Testing arithmetic between Fractions and integers
 -1/2 + 4 = 3+1/2
 -1/2 - 4 = -4+1/2
 -1/2 * 4 = -2
 -1/2 / 4 = -1/8
 3 + -1/2 = 2+1/2
 3 - -1/2 = 3+1/2
 3 * -1/2 = -1+1/2
 3 / -1/2 = -6

 ----- Testing shorthand arithmetic assignment on Fractions
 1/6 += 4 = 4+1/6
 4+1/6 -= 4 = 1/6
 1/6 *= 4 = 2/3
 2/3 /= 4 = 1/6
 4 += -1/2 = 3+1/2
 3+1/2 -= -1/2 = 4
 4 *= -1/2 = -2
 -2 /= -1/2 = 4
 -1/2 += 5 = 4+1/2
 4+1/2 -= 5 = -1/2
 -1/2 *= 5 = -2+1/2
 -2+1/2 /= 5 = -1/2

 ----- Testing shorthand arithmetic assignment using integers
 -1/3 += 3 = 2+2/3
 2+2/3 -= 3 = -1/3
 -1/3 *= 3 = -1
 -1 /= 3 = -1/3

 ----- Testing increment/decrement prefix and postfix
 Now g = -1/3
 g++ = -1/3
 Now g = 2/3
 ++g = 1+2/3
 Now g = 1+2/3
 g-- = 1+2/3
 Now g = 2/3
 --g = -1/3
 Now g = -1/3
 Program ended with exit code: 0
 */

