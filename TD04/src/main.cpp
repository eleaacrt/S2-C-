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

int nb_letters(std::string const &str);
std::vector<std::string> split_string(std::string const &str);

bool is_palindrome(std::string const &string);

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
    const int sum{std::accumulate(vect.begin(), vect.end(), 0)};
    std::cout << "la somme totale des éléments du vecteur est : " << sum << std::endl;
}

// savoir si le caractère est un espace ou non
auto const is_space = [](char letter)
{
    return letter == ' ';
};

// nombre de lettre dans le premier mot d'une phrase
int nb_letters(std::string const &str)
{
    auto const it{std::find_if(str.begin(), str.end(), is_space)};
    auto const nb_letters{std::distance(str.begin(), it)};
    return nb_letters;
}

// ranger les mots dans un vecteur
std::vector<std::string> split_string(std::string const &str)
{
    std::vector<std::string> vect_string{};
    for (auto it{str.begin()}; it <= str.end(); it++)
    {
        auto const it_space{std::find_if(it, str.end(), is_space)};
        std::string word{it, it_space};
        vect_string.push_back(word);
        it = it_space;
    }
    return vect_string;
}

// afficher les éléments du vecteur de string
void display_vect_string(std::vector<std::string> const vect)
{
    std::cout << "[ ";
    for (auto it{vect.begin()}; it != vect.end(); it++)
    {
        std::cout << *it << ", ";
    }
    std::cout << "]";
    std::cout << std::endl;
}

// palindrome
bool is_palindrome(std::string const &str)
{
    if (std::equal(str.cbegin(), str.cbegin() + str.size() / 2, str.crbegin())){
        std::cout << str << " est un palindrome" <<  std::endl;
        return true;
    } else {
        std::cout << str << " n'est pas un palindrome" << std::endl;
        return false;
    }
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

    // phrases
    std::string phrase{"bonjour je suis une phrase"};
    std::cout << "il y a " << nb_letters(phrase) << " lettres dans le premier mot de la phrase : " << phrase << std::endl;

    // ranger les mots dans un vecteur
    std::vector<std::string> vect_string{split_string(phrase)};
    display_vect_string(vect_string);

    // test palindrome
    std::string const palindrome{"pouleeluop"};
    std::string const palindrome2{"pouleluop"};
    std::string const no_palindrome{"ozirfeojrnv"};

    is_palindrome(palindrome);
    is_palindrome(palindrome2);
    is_palindrome(no_palindrome);

    return 0;
}