#include <iostream>
#include "./utils.hpp"

unsigned int gcd(unsigned int int1, unsigned int int2)
{
    unsigned int min{0};
    unsigned int max{0};
    if (int1 < int2)
    {
        min = int1;
        max = int2;
    }
    else
    {
        max = int1;
        min = int2;
    }

    unsigned int pgcd{1};

    for (unsigned int i{1}; i <= min; i++)
    {
        if (max % i == 0)
        {
            if (min % i == 0)
            {
                pgcd = i;
            }
        }
    }
    return pgcd;
}

Fraction simplify(Fraction fract)
{
    unsigned int fract_gcd{gcd(fract.numerator, fract.denominator)};
    unsigned int new_numerator{fract.numerator / fract_gcd};
    unsigned int new_denominator{fract.denominator / fract_gcd};
    Fraction new_fract{new_numerator, new_denominator};
    return new_fract;
};