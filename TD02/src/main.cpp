#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void display(std::vector<int> &vec);

bool is_sorted(std::vector<int> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}

void bubble_sort(std::vector<int> &vec)
{
    for (int i = vec.size(); i > 0; i--)
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
    for (unsigned long i = 0; i < vec.size(); i++)
    {
        unsigned long min_i = i;

        for (unsigned long j = i; j < vec.size(); j++)
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

// affichage
void display(std::vector<int> &vec)
{
    std::cout << "[ ";
    for (unsigned long i = 0; i < (vec.size() - 1); i++)
    {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[vec.size() - 1];
    std::cout << " ]" << std::endl;
}

int main()
{
    // bubble sort
    std::vector<int> array{12, 78, 35, 22, 9, 4, 1, 32, 56};
    display(array);
    std::cout << " -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --" << std::endl;

    bubble_sort(array);
    display(array);
    std::cout << " -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --" << std::endl;

    // selection sort
    std::vector<int> array2{12, 78, 35, 22, 9, 4, 1, 32, 56};
    selection_sort(array2);
    display(array2);
    std::cout << " -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --" << std::endl;
}