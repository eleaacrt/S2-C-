#include <iostream>
#include <string>
#include <cmath>

size_t folding_string_hash(std::string const &s, size_t max);
size_t folding_string_ordered_hash(std::string const &s, size_t max);
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m);


size_t folding_string_hash(std::string const &s, size_t max)
{
    size_t hash{0};
    for (auto it{s.begin()}; it != s.end(); it++)
    {
        hash += *it;
    }
    return hash % max;
}

size_t folding_string_ordered_hash(std::string const &s, size_t max)
{
    size_t hash{0};
    for (size_t i{1}; i <= s.size(); i++)
    {
        hash += (s[i] * i);
    }
    return hash % max;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    size_t hash{0};
    for (size_t i{0}; i < s.size(); i++){
        hash += (s[i] * std::pow(p, i));
    }
    return hash % m;
}

int main()
{
    const int max{1024};

    // utilisation de la fonction de hashage sans prise en compte de la position du caractère
    std::cout << folding_string_hash("hello", max) << std::endl;
    std::cout << folding_string_hash("olleh", max) << std::endl;

    // utilisation de la fonction de hashage en prenant en compte la position du caractère
    std::cout << folding_string_ordered_hash("hello", max) << std::endl;
    std::cout << folding_string_ordered_hash("olleh", max) << std::endl;

    // utilisation de la méthode polynomiale
    std::cout << polynomial_rolling_hash("hello", 31, max) << std::endl;
    std::cout << polynomial_rolling_hash("olleh", 31, max) << std::endl;

    return 0;
}