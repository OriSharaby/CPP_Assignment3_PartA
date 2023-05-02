#include "Fraction.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
namespace ariel{

    Fraction:: Fraction(){
    this->numerator = 0;
    this->denominator = 1;
    }

    Fraction::Fraction(float num){
    this->numerator = num;
    this->denominator = 1;
    }

    Fraction::Fraction(const Fraction& other){
        this->setNumerator(other.numerator);
        this->setDenominator(other.denominator);
    }

    Fraction::Fraction(int numerator,int denominator){
        if(denominator == 0){
            throw std::runtime_error("Denominator cannot be 0!");

        }
        this->numerator = numerator;
        this->denominator = denominator;
    };
    int Fraction::getNumerator(){
        return this->numerator;
    }
    
    int Fraction::getDenominator(){
        return this->denominator;
    }
    void Fraction::setNumerator(int num){

    }
    void Fraction::setDenominator(int num){

    }
    std::ostream &operator<<(std::ostream &stream, const Fraction &fraction) { return stream; }
    std::istream &operator>>(std::istream &stream, const Fraction &fraction) { return stream; }
    Fraction &Fraction::operator++() { return *this; }
    Fraction Fraction::operator++(int dummy) { return Fraction(1,1); }
    Fraction &Fraction::operator--() { return *this; }
    Fraction Fraction::operator--(int dummy) { return Fraction(1,1); }
    Fraction Fraction::operator+(const Fraction& other) const {return Fraction(1,1);}
    Fraction Fraction::operator-(const Fraction& other) const {return Fraction(1,1);}
    Fraction Fraction:: operator*(const Fraction& other) const {return Fraction(1,1);}
    Fraction Fraction:: operator/(const Fraction& other) const {return Fraction(1,1);}
    Fraction Fraction:: operator+(float num){return Fraction(1,1);}
    Fraction Fraction:: operator-(float num){return Fraction(1,1);}
    Fraction Fraction:: operator*(float num){return Fraction(1,1);}
    Fraction Fraction:: operator/(float num){return Fraction(1,1);}
    Fraction operator+(float num, const Fraction& other){return Fraction(1,1);}
    Fraction operator-(float num, const Fraction& other){return Fraction(1,1);}
    Fraction operator*(float num, const Fraction& other){return Fraction(1,1);}
    Fraction operator/(float num, const Fraction& other){return Fraction(1,1);}
    bool Fraction::operator<(float num){return false;}
    bool Fraction::operator<=(float num){return false;}
    bool Fraction::operator>(float num){return false;}
    bool Fraction::operator>=(float num){return false;}
    bool Fraction::operator==(float num){return false;}
    bool Fraction::operator<(const Fraction& other) const {return false;}
    bool Fraction::operator<=(const Fraction& other) const {return false;}
    bool Fraction::operator>(const Fraction& other) const {return false;}
    bool Fraction::operator>=(const Fraction& other) const {return false;}
    bool Fraction::operator==(const Fraction& other) const {return false;}
    bool operator<(float num, const Fraction& other){return false;}
    bool operator<=(float num, const Fraction& other){return false;}
    bool operator>(float num, const Fraction& other){return false;}
    bool operator>=(float num, const Fraction& other){return false;}
    bool operator==(float num, const Fraction& other){return false;}

}