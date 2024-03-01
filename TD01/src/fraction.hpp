// - `add` : prend deux fractions en paramètre et retourne la **somme** des deux fractions.
// - `sub` : prend deux fractions en paramètre et retourne la **différence** des deux fractions.
// - `mul` : prend deux fractions en paramètre et retourne le **produit** des deux fractions.
// - `div` : prend deux fractions en paramètre et retourne le **quotient** des deux fractions.
// - `display` : prend une fraction en paramètre et affiche la fraction sous la forme `numerator/denominator`.

#pragma once
#include <iostream>

struct Fraction
{
    unsigned int numerator{0};
    unsigned int denominator{1};

    // conversion en float
    operator float() const;
};

// add, sub, mul, div, display
Fraction operator+=(Fraction fract1, Fraction const &fract2);
Fraction operator-=(Fraction fract, Fraction const &fract2);
Fraction operator*=(Fraction fract, Fraction const &fract2);
Fraction operator/=(Fraction fract, Fraction const &fract2);
std::ostream &operator<<(std::ostream &os, Fraction const &fract);

// ==, !=
bool operator==(Fraction const &fract, Fraction const &fract2);
bool operator!=(Fraction const &fract, Fraction const &fract2);

// <, >, <=, >=
bool operator<(Fraction const &fract, Fraction const &fract2);
bool operator>(Fraction const &fract, Fraction const &fract2);
bool operator<=(Fraction const &fract, Fraction const &fract2);
bool operator>=(Fraction const &fract, Fraction const &fract2);
