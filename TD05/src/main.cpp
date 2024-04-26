#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>

// -------------------------------------------------------------------------------------------

// EXERCICE 3

// -------------------------------------------------------------------------------------------

enum class CardKind
{
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue
{
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

struct Card
{
    CardKind kind;
    CardValue value;

    size_t hash() const
    {
        return static_cast<size_t>(kind) * 13 + static_cast<size_t>(value);
    }
};

bool operator==(Card card, Card const &card2)
{
    return (card.kind == card2.kind && card.value == card2.value);
};

size_t hash(Card card)
{
    return static_cast<size_t>(card.kind) * 13 + static_cast<size_t>(card.value);
}

namespace std
{
    template <>
    struct hash<Card>
    {
        size_t operator()(Card const &card) const
        {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size)
{
    std::vector<Card> cards{};
    cards.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::unordered_map<Card, size_t> count_cards(std::vector<Card> const &cards)
{
    std::unordered_map<Card, size_t> count_cards{};
    for (Card const &card : cards)
    {
        auto card_count{count_cards.find(card)};
        if (card_count != count_cards.end())
        {
            card_count->second++;
        }
        else
        {
            count_cards.insert({card, 1});
        }
    }
    return count_cards;
}

std::string card_name(Card const &card)
{
    std::string name{};

    unsigned int card_value{(static_cast<unsigned int>(card.value) + 2) % 14};

    if (card_value < 10)
    {
        name += '0' + card_value;
    }
    else if (card_value == 10)
    {
        name += "10";
    }
    else if (card_value == 11)
    {
        name += 'V';
    }
    else if (card_value == 12)
    {
        name += 'Q';
    }
    else if (card_value == 13)
    {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart)
    {
        name += "Heart";
    }
    else if (card.kind == CardKind::Diamond)
    {
        name += "Diamond";
    }
    else if (card.kind == CardKind::Club)
    {
        name += "Club";
    }
    else if (card.kind == CardKind::Spade)
    {
        name += "Spade";
    }
    return name;
}

// -------------------------------------------------------------------------------------------

// EXERCICE 1

// -------------------------------------------------------------------------------------------

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

// -------------------------------------------------------------------------------------------

// EXERCICE 2

// -------------------------------------------------------------------------------------------

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

    // -------------------------------------------------------------------------------------------

    // EXERCICE 1

    // -------------------------------------------------------------------------------------------
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

    // -------------------------------------------------------------------------------------------

    // EXERCICE 2

    // -------------------------------------------------------------------------------------------
    std::vector<std::pair<std::string, float>> get_robots{get_robots_fix(500)};
    std::unordered_map<std::string, std::vector<float>> robots_fixes{robots_fixes_map(get_robots)};

    display_robots_fix(robots_fixes);

    // -------------------------------------------------------------------------------------------

    // EXERCICE 3

    // -------------------------------------------------------------------------------------------
    std::vector<Card> cards{get_cards(100)};
    std::unordered_map<Card, size_t> count_cards_map{count_cards(cards)};
    for (Card const &card : cards)
    {
        std::cout << card_name(card) << std::endl;
    }

    return 0;
}