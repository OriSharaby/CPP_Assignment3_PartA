#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"
#include "doctest.h"
#include <sstream>
#include <limits>
#include <vector>
using namespace ariel;

TEST_CASE("Test constructor and division by zero")
{
    CHECK(Fraction(5,10)==0.5);
    CHECK(Fraction(5,-10)==-0.5);
    CHECK(Fraction(5,5)==1);
    CHECK(Fraction(5,-5)==-1);
    CHECK_NOTHROW(Fraction(5,5));
    CHECK_NOTHROW(Fraction(5,-5));
    CHECK_NOTHROW(Fraction(0,5));
    CHECK_NOTHROW(Fraction(0,-5));
    CHECK_THROWS(Fraction(5,0));
    CHECK_THROWS(Fraction(-5,0));

}

TEST_CASE("Test operator prefix and posfix(++,--)")
{
    Fraction f1 = Fraction(3, 1);
    Fraction f2 = Fraction(3, 6);
    Fraction f3 = Fraction(1, 2);

    CHECK(f1++ == Fraction(4,1));
    CHECK(f2++ == 1.5);
    CHECK(f2++ == Fraction(5,2));
    
    CHECK(f3-- == Fraction(-1,2));
    CHECK(f1-- == 3);
    CHECK(f1-- == Fraction(2,1));

}
TEST_CASE("Test operator (==)")
{   
    CHECK(Fraction(9,16)+Fraction(19,80)==Fraction(4,5));
    CHECK(float(9/16)+Fraction(19,80)==Fraction(4,5));
    CHECK(Fraction(9,16)+float(19/80)==Fraction(4,5));

    CHECK(Fraction(8,15)-Fraction(6,20)==Fraction(5,6));
    CHECK(float(8/15)-Fraction(6,20)==Fraction(5,6));
    CHECK(Fraction(8,15)-float(6/20)==Fraction(5,6));

    CHECK(Fraction(1,2)*Fraction(1,4)==Fraction(2,16));
    CHECK(float(1/2)*Fraction(1,4)==Fraction(2,16));
    CHECK(Fraction(1,2)*float(1/4)==Fraction(2,16));

    CHECK(Fraction(3,20)/Fraction(3,16)==Fraction(4,5));
    CHECK(float(3/20)/Fraction(3,16)==Fraction(4,5));
    CHECK(Fraction(3,20)/float(3/16)==Fraction(4,5));
}

TEST_CASE("Test operators (<,>,<=,>=) ")
{
    CHECK(Fraction(2,16)<0.5);
    CHECK(Fraction(4,16)<=0.25);
    CHECK(Fraction(4,16)>0.1);
    CHECK(Fraction(2,16)>=0.115);
    CHECK(Fraction(4,16)==0.125);

    CHECK(0.2<Fraction(8,32));
    CHECK(0.125<=Fraction(4,32));
    CHECK(0.5>Fraction(4,32));
    CHECK(0.125>=Fraction(4,32));
    CHECK(0.25==Fraction(8,32));

    CHECK(Fraction(2,16)<Fraction(8,32));
    CHECK(Fraction(4,16)<=Fraction(8,32));
    CHECK(Fraction(4,16)>Fraction(4,32));
    CHECK(Fraction(4,16)>=Fraction(4,32));
    CHECK(Fraction(4,16)==Fraction(8,32));
}

TEST_CASE("Input stream operator (>>)") {
        std::stringstream st("5 8");
        Fraction frac;
        st >> frac;
        CHECK_EQ(frac, Fraction{5, 8});
}

TEST_CASE("Output stream operatr(<<)") {
        std::stringstream st;
        Fraction frac{3, 4};
        st << frac;
        CHECK(st.str() == "3/4");
}


// TEST_CASE("Test 1: Fraction constructor throws exception when denominator is zero")
// {
//     CHECK_THROWS(Fraction(5, 0));
//     CHECK_THROWS(Fraction(-5, 0));
//     CHECK_NOTHROW(Fraction(5, -5));
//     CHECK_NOTHROW(Fraction(-5, -5));
// }

// TEST_CASE("Test 2: Fraction constructor shouldn't throw exception when only the numerator is zero")
// {
//     CHECK_NOTHROW(Fraction(0, 5));
//     CHECK_NOTHROW(Fraction(0, -5));
// }

// TEST_CASE("Test 3: Fraction constructor should reduce the fraction")
// {
//     Fraction a (2, 8);
//     Fraction b (-2, 8);
//     Fraction c (2, -8);
//     Fraction d (-2, -8);
//     Fraction e (6, 8);

//     CHECK((double)a == 0.25);
//     CHECK((double)b == -0.25);
//     CHECK((double)c == -0.25);
//     CHECK((double)d == 0.25);
//     CHECK((double)e == 0.75);
// }

// TEST_CASE("Test 4: Fraction constructor should reduce the fraction when the numerator is zero")
// {
//     Fraction a (0,8); 
//     Fraction b (0,-8);

//     CHECK((double)a == 0);
//     CHECK((double)b == 0);
// }

// TEST_CASE("Test 5: Arithmetics with fractions")
// {
//     Fraction a (1,4);
//     Fraction b (2,5);

//     CHECK((double)(a * b) == 0.1);
//     CHECK((double)(a / b) == 0.625);
//     CHECK((double)(a + b) == 0.65);
//     CHECK((double)(a - b) == -0.15);
// }

// TEST_CASE("Test 6: Comparison operators with fractions")
// {
//     Fraction a (1,4);
//     Fraction b (1,2);
//     Fraction c (2,4);

//     CHECK((a != b) == true);
//     CHECK((b != c) == false);
//     CHECK((a == b) == false);
//     CHECK((b == c) == true);
//     CHECK((a < b) == true);
//     CHECK((b < c) == false);
//     CHECK((a > b) == false);
//     CHECK((b <= c) == true);
//     CHECK((a <= b) == true);
//     CHECK((a >= b) == false);
// }