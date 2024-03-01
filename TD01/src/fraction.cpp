// struct Fraction
// {
//     unsigned int numerator {0};
//     unsigned int denominator {1};

//     Fraction add (Fraction fract1, Fraction fract2);
//     Fraction sub (Fraction fract1, Fraction fract2);
//     Fraction mul (Fraction fract1, Fraction fract2);
//     Fraction div (Fraction fract1, Fraction fract2);
//     Fraction display (Fraction fract);
// };

#include <iostream>
#include <string>
#include "./fraction.hpp"

// addition
// Fraction operator+(Fraction const &fract, Fraction const &fract2)
// {
//     unsigned int new_numerator = fract2.denominator * fract.numerator + fract.denominator * fract2.numerator;
//     unsigned int new_denominator = fract2.denominator * fract.denominator;
//     Fraction new_fract{new_numerator, new_denominator};
//     return new_fract;
// };
Fraction operator+=(Fraction fract, Fraction const &fract2)
{
    fract.numerator = fract2.denominator * fract.numerator + fract.denominator * fract2.numerator;
    fract.denominator = fract2.denominator * fract.denominator;
    return fract;
};

// soustraction
// Fraction operator-(Fraction const &fract, Fraction const &fract2)
// {
//     unsigned int new_numerator = fract.denominator * fract2.numerator - fract2.denominator * fract.numerator;
//     unsigned int new_denominator = fract.denominator * fract2.denominator;
//     Fraction new_fract{new_numerator, new_denominator};
//     return new_fract;
// };
Fraction operator-=(Fraction fract, Fraction const &fract2)
{
    fract.numerator = fract.denominator * fract2.numerator - fract2.denominator * fract.numerator;
    fract.denominator = fract.denominator * fract2.denominator;
    return fract;
};

// multiplication
// Fraction operator*(Fraction const &fract, Fraction const &fract2)
// {
//     unsigned int new_numerator = fract2.numerator * fract.numerator;
//     unsigned int new_denominator = fract2.denominator * fract.denominator;
//     Fraction new_fract{new_numerator, new_denominator};
//     return new_fract;
// };
Fraction operator*=(Fraction fract, Fraction const &fract2)
{
    fract.numerator = fract2.numerator * fract.numerator;
    fract.denominator = fract2.denominator * fract.denominator;
    return fract;
};

// division
// Fraction operator/(Fraction const &fract, Fraction const &fract2)
// {
//     unsigned int new_numerator = fract2.numerator * fract.denominator;
//     unsigned int new_denominator = fract2.denominator * fract.numerator;
//     Fraction new_fract{new_numerator, new_denominator};
//     return new_fract;
// };
Fraction operator/=(Fraction fract, Fraction const &fract2)
{
    fract.numerator = fract2.numerator * fract.denominator;
    fract.denominator = fract2.denominator * fract.numerator;
    return fract;
};

// display
std::ostream &operator<<(std::ostream &os, Fraction const &fract)
{
    return os << fract.numerator << " / " << fract.denominator;
};

// comparaison
bool operator==(Fraction const &fract, Fraction const &fract2)
{
    return (fract.numerator * fract2.denominator == fract2.numerator * fract.denominator);
};

bool operator!=(Fraction const &fract, Fraction const &fract2)
{
    return !(fract == fract2);
};

bool operator<(Fraction const &fract, Fraction const &fract2)
{
    return (fract.numerator * fract2.denominator < fract2.numerator * fract.denominator);
};

bool operator>(Fraction const &fract, Fraction const &fract2)
{
    return (fract2 < fract);
};

bool operator<=(Fraction const &fract, Fraction const &fract2)
{
    return (fract < fract2 || fract == fract2);
};

bool operator>=(Fraction const &fract, Fraction const &fract2)
{
    return (fract2 <= fract);
};


// float conversion
Fraction::operator float() const
{
    return static_cast<float>(numerator) / static_cast<float>(denominator);
};