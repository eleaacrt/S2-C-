#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;
};

size_t folding_string_hash(std::string const &s, size_t max);
size_t folding_string_ordered_hash(std::string const &s, size_t max);
size_t polynomial_rolling_hash(const std::string &s, size_t p, size_t m);

float sum_robots_fix(std::vector<float> &map);

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

size_t polynomial_rolling_hash(const std::string &s, size_t p, size_t m)
{
    size_t hash{0};
    size_t new_pow{1};
    for (size_t i{0}; i < s.size(); i++)
    {
        hash += (s[i] * new_pow);
        new_pow *= p;
    }
    return hash % m;
}

// réparation de robots
std::string random_name(size_t size)
{
    std::string name{""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size)
{
    std::vector<std::pair<std::string, float>> robots_fix{};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        // random name
        std::string robotName{random_name(2)};
        // random cost
        float cost{static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const &robots_fixes)
{
    // std::sort(robots_fixes.begin(), robots_fixes.end());
    std::unordered_map<std::string, std::vector<float>> robots_fixes_map{};

    for (auto const &pair : robots_fixes)
    {
        auto robotName{robots_fixes_map.find(pair.first)};

        if (robotName != robots_fixes_map.end())
        {
            robotName->second.push_back(pair.second);
        }
        else
        {
            robots_fixes_map.insert({pair.first, {pair.second}});
        }
    }
    return robots_fixes_map;
}

void display_robots_fix(std::unordered_map<std::string, std::vector<float>> &map)
{
    for (std::pair p : map)
    {
        std::cout << p.first << " : " << sum_robots_fix(p.second) << std::endl;
    }
}

float sum_robots_fix(std::vector<float> &map)
{
    float sum{0};
    for (float p : map)
    {
        sum += p;
    }
    return sum;
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

    // exercice 2 - robots
    std::vector<std::pair<std::string, float>> get_robots{get_robots_fix(500)};
    std::unordered_map<std::string, std::vector<float>> robots_fixes{robots_fixes_map(get_robots)};

    display_robots_fix(robots_fixes);


    return 0;
}