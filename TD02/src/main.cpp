#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "ScopedTimer.hpp"

void display(std::vector<int> &vec);

bool is_sorted(std::vector<int> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}

std::vector<int> generate_random_vector(size_t const size, int const max = 100)
{
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]()
                  { return std::rand() % max; });
    return vec;
}

void bubble_sort(std::vector<int> &vec)
{
    ScopedTimer timer("bubble sort");
    for (unsigned long i{vec.size()}; i > 0; i--)
    {
        for (unsigned long j = 0; j < (vec.size() - 1); j++)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// tri par selection
void selection_sort(std::vector<int> &vec)
{
    ScopedTimer timer("selection sort");
    for (unsigned long i{0}; i < vec.size(); i++)
    {
        unsigned long min_i = i;

        for (unsigned long j{i}; j < vec.size(); j++)
        {
            if (vec[min_i] > vec[j])
            {
                min_i = j;
            }
        }

        if (min_i != i)
        {
            std::swap(vec[i], vec[min_i]);
        }
    }
};

// tri fusion recursif
void merge_sort_merge(std::vector<int> &vec, size_t const left, size_t const middle, size_t const right)
{

    // on défini la taille des sous tableaux
    int const left_size = middle - left + 1;
    int const right_size = right - middle;

    // création des sous tableaux
    std::vector<int> left_vec(left_size);
    std::vector<int> right_vec(right_size);

    for (size_t i{0}; i < left_size; i++)
    {
        left_vec[i] = vec[left + i];
    }

    for (size_t i{0}; i < right_size; i++)
    {
        right_vec[i] = vec[middle + i + 1];
    }

    // fusion des sous tableaux
    size_t i_left{0};
    size_t i_right{0};
    size_t to_change{left};

    while (i_left < left_size && i_right < right_size)
    {
        if (left_vec[i_left] <= right_vec[i_right])
        {
            vec[to_change] = left_vec[i_left];
            i_left++;
        }
        else
        {
            vec[to_change] = right_vec[i_right];
            i_right++;
        }
        to_change++;
    }

    while (i_left < left_size)
    {
        vec[to_change] = left_vec[i_left];
        i_left++;
        to_change++;
    }

    while (i_right < right_size)
    {
        vec[to_change] = right_vec[i_right];
        i_right++;
        to_change++;
    }
}

void merge_sort(std::vector<int> &vec, size_t const left, size_t const right)
{
    if (left < right)
    {
        size_t middle = (left + right) / 2;
        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);
        merge_sort_merge(vec, left, middle, right);
    }
}

void merge_sort(std::vector<int> &vec)
{
    ScopedTimer timer("merge sort");
    merge_sort(vec, 0, vec.size() - 1);
}

// affichage
void display(std::vector<int> &vec)
{
    std::cout << "[ ";
    for (unsigned long i{0}; i < (vec.size() - 1); i++)
    {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[vec.size() - 1];
    std::cout << " ]" << std::endl;
}

int search(std::vector<int> &vec, int const value)
{
    // on trie le tableau avant d'effectuer une dichotomie pour éviter une erreur
    std::sort(vec.begin(), vec.end());

    // indice du début et fin du tableau
    int left = 0;
    int right = vec.size() - 1;

    // tant que l'indice de début est inférieur à l'indice de fin
    while (right >= left)
    {
        // on déifni l'indice du milieu
        int middle = (left + right) / 2;
        int value_middle = vec[middle];

        if (vec[middle] == value)
        {
            return middle;
        }

        else if (vec[middle] < value)
        {
            left = middle + 1;
            // creation du sous tableau
            std::vector<int> new_tab(vec.begin() + left, vec.end());
            search(new_tab, value);
        }

        else
        {
            right = middle - 1;
            // creation du sous tableau
            std::vector<int> new_tab(vec.begin(), vec.begin() + right);
            search(new_tab, value);
        }
    }

    return -1;
}

int main()
{
    // bubble sort
    std::vector<int> random_vect1{generate_random_vector(1000)};
    // display(random_vect1);
    bubble_sort(random_vect1);
    // display(random_vect1);
    std::cout << " -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --" << std::endl;

    // selection sort
    std::vector<int> random_vect2{generate_random_vector(1000)};
    // display(random_vect2);
    selection_sort(random_vect2);
    // display(random_vect2);
    std::cout << " -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --" << std::endl;

    // merge sort
    std::vector<int> random_vect3{generate_random_vector(1000)};
    // display(random_vect3);
    merge_sort(random_vect3);
    // display(random_vect3);
    std::cout << " -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --" << std::endl;

    // test de sort
    std::vector<int> random_vect4{generate_random_vector(1000)};
    // display(random_vect4);
    ScopedTimer timer("classic sort");
    std::sort(random_vect4.begin(), random_vect4.end());
    // display(random_vect4);

    // dichotomie
    std::vector<int> random_vect5{0, 1, 2, 3, 4, 5};
    std::sort(random_vect5.begin(), random_vect5.end());
    int value = 3;
    int index = search(random_vect5, value);
    std::cout << value << " dans le tableau vec 5 est à l'indice index : " << index << std::endl;
    int value2 = 50;
    int index2 = search(random_vect5, value2);
    std::cout << value2 << " dans le tableau vec 5 est à l'indice index : " << index2 << std::endl;


    // TEST DE PERFORMANCE ----------------------------------

    // au vu des resultats, on peut voir que le tri de selection est le plus rapide, suivi du tri à bulles, puis la librairie std et enfin le tri de fusion.
    // le tri de fusion est le plus lent car il est recursif et utilise beaucoup de mémoire.
    // le tri de selection est le plus rapide car il est simple et ne fait pas beaucoup de comparaisons. (10*10 maximum avec un vecteur de 10 éléments)
    // avec 10 éléments dans le vecteur :
    // bubble sort : 2.471us(0.002471ms)
    // selection sort : 1.29us(0.00129ms)
    // merge sort : 9.717us(0.009717ms)
    // classic sort : 5.722us(0.005722ms)

    // en revanche, lorsque nous paramétrons les vecteurs avec 1000 éléments, le tri de fusion devient tout de suite bien plus rapide que le tri à bulles et le tri de selection.
    // le tri fourni dans la bibliothèque standard reste tout de même le plus rapide.
    // avec 1000 éléments dans le vecteur :
    // bubble sort : 12668.9us (12.6689ms)
    // selection sort : 3728.49us (3.72849ms)
    // merge sort : 1149.98us (1.14998ms)
    // classic sort : 36.421us (0.036421ms)

    // conclusion :
    // la récursivité est bien plus rapide lorsque le vecteur est grand, mais elle utilise beaucoup de mémoire.
    // le tri de selection est le plus rapide pour un petit vecteur, mais il est très lent pour un grand vecteur.



}