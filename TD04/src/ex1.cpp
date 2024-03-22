#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <random>
#include <algorithm>

std::vector<int> generate_random_vector(size_t const size, int const max);
void display_vect(std::vector<int> const vect);
bool is_in_vect(std::vector<int> const vect, int const value);
void count_occurence(std::vector<int> const vect, int const value);
void sort_vect(std::vector<int> const &vect);
void sum_values(std::vector<int> const vect);


// fonction utilisée dans le TD02
std::vector<int> generate_random_vector(size_t const size, int const max = 100)
{
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]()
                  { return std::rand() % max; });
    return vec;
}

// afficher les valeurs du tableau
void display_vect(std::vector<int> const vect)
{
    for (auto it{vect.begin()}; it != vect.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// vérifier si une valeur est dans le tableau
bool is_in_vect(std::vector<int> const vect, int const value)
{
    auto it{std::find(vect.begin(), vect.end(), value)};
    if (it != vect.end())
    {
        std::cout << "La valeur " << value << " a été trouvée à la position ";
        std::cout << it - vect.begin() + 1 << " en partant de 1" << std::endl;
        return true;
    }
    else
        std::cout << "La valeur " << value << " n'est pas dans le tableau." << std::endl;
    return false;
}

// compter le nombre d'occurences d'une valeur dans le tableau
void count_occurence(std::vector<int> const vect, int const value)
{
    if (is_in_vect(vect, value) == true)
    {
        const auto num_items{std::count(vect.begin(), vect.end(), value)};
        std::cout << "La valeur " << value << " est présente " << num_items << " fois dans le tableau" << std::endl;
    }
}

void sort_vect(std::vector<int> &vect)
{
    std::sort(vect.begin(), vect.end());
}

void sum_values(std::vector<int> const vect)
{
    const int sum {std::accumulate(vect.begin(), vect.end(), 0)};
    std::cout << "la somme totale des éléments du vecteur est : " << sum << std::endl;
}

int main()
{
    // générer un tableau aléatoire de valeurs entre 0 et 100
    std::vector<int> new_vect{generate_random_vector(10)};

    // afficher le nouveau tableau
    display_vect(new_vect);

    // vérifier si la valeur 78 est dedans
    is_in_vect(new_vect, 78);
    // vérifier si la valeur 2 est dedans
    is_in_vect(new_vect, 2);

    // compter le nombre d'occurence des valeurs 2 et 78
    count_occurence(new_vect, 2);
    count_occurence(new_vect, 78);

    // trier le vecteur puis l'afficher
    sort_vect(new_vect);
    display_vect(new_vect);

    // calculer la somme des éléments du vecteur 
    sum_values(new_vect);

    return 0;
}