#include <iostream>
#include <string>
#include "fraction.hpp"
#include "utils.hpp"

int main()
{
    Fraction f1{};
    Fraction f2{};

    std::cout << "saisissez le numérateur de la fraction 1 : ";
    std::cin >> f1.numerator;
    std::cout << "saisissez le dénominateur de la fraction 1 : ";
    std::cin >> f1.denominator;
    std::cout << "saisissez le numérateur de la fraction 2 : ";
    std::cin >> f2.numerator;
    std::cout << "saisissez le dénominateur de la fraction 2 : ";
    std::cin >> f2.denominator;

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    std::cout << "somme : " << (f1 += f2) << std::endl;
    std::cout << "somme simplifiée : " << simplify(f1 += f2) << std::endl;

    std::cout << "soustraction : " << (f1 -= f2) << std::endl;
    std::cout << "soustraction simplifiée : " << simplify(f1 -= f2) << std::endl;

    std::cout << "multiplication : " << (f1 *= f2) << std::endl;
    std::cout << "multiplication simplifiée : " << simplify(f1 *= f2) << std::endl;

    std::cout << "division : " << (f1 /= f2) << std::endl;
    std::cout << "division simplifiée : " << simplify(f1 /= f2) << std::endl;

    std::cout << "f1 < f2 : " << (f1 < f2) << std::endl;
    std::cout << "f1 > f2 : " << (f1 > f2) << std::endl;
    std::cout << "f1 <= f2 : " << (f1 <= f2) << std::endl;
    std::cout << "f1 >= f2 : " << (f1 >= f2) << std::endl;
    std::cout << "f1 == f2 : " << (f1 == f2) << std::endl;
    std::cout << "f1 != f2 : " << (f1 != f2) << std::endl;

    float f1_float {static_cast<float>(f1)};
    std::cout << "f1_float : " << f1_float << std::endl;

    return 0;
}