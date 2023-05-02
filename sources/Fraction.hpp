#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace ariel{ 
class Fraction{
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int ,int);
        Fraction(float);
        Fraction(const Fraction&);
        Fraction();
        int getNumerator();
        int getDenominator();
        void setNumerator(int);
        void setDenominator(int);
        friend std::ostream &operator<<(std::ostream &, const Fraction &);
        friend std::istream &operator>>(std::istream &, const Fraction &);
        Fraction &operator++();
        Fraction operator++(int dummy);
        Fraction &operator--();
        Fraction operator--(int dummy);
        Fraction operator+(const Fraction&) const;
        Fraction operator-(const Fraction&) const;
        Fraction operator*(const Fraction&) const;
        Fraction operator/(const Fraction&) const;
        Fraction operator+(float);
        Fraction operator-(float);
        Fraction operator*(float);
        Fraction operator/(float);
        friend Fraction operator+(float, const Fraction&);
        friend Fraction operator-(float, const Fraction&);
        friend Fraction operator*(float, const Fraction&);
        friend Fraction operator/(float, const Fraction&);
        bool operator<(float);
        bool operator<=(float);
        bool operator>(float);
        bool operator>=(float);
        bool operator==(float);
        bool operator<(const Fraction&)const;
        bool operator<=(const Fraction&)const;
        bool operator>(const Fraction&)const;
        bool operator>=(const Fraction&)const;
        bool operator==(const Fraction&)const;
        friend bool operator<(float, const Fraction&);
        friend bool operator<=(float, const Fraction&);
        friend bool operator>(float, const Fraction&);
        friend bool operator>=(float, const Fraction&);
        friend bool operator==(float, const Fraction&);
};
}