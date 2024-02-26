#include <iostream>

int main()
{
    int n{};

    std::cout << "Entrez un entier positif: ";
    std::cin >> n;

    for (int i{1}; i <= n; ++i)
    {
        for (int j{1}; j <= i; ++j)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    std::cout << "-------------------" << std::endl;

    for (int i{1}; i <= n; ++i)
    {
        if (i % 2 != 0)
        {
            for (int j{1}; j <= (n - i) / 2; ++j)
            {
                std::cout << " ";
            }
            for (int j{1}; j <= i; ++j)
            {
                std::cout << "*";
            }
            std::cout << "\n";
        }
    }

    std::cout << "-------------------" << std::endl;

    for (int i{1}; i <= n; ++i)
    {
        std::cout << "*";
    }

    std::cout << "\n";

    for (int i{1}; i <= n - 2; ++i)
    {
        std::cout << "*";
        for (int j{1}; j <= n - 2; ++j)
        {
            std::cout << " ";
        }
        std::cout << "*";
        std::cout << "\n";
    }

    for (int i{1}; i <= n; ++i)
    {
        std::cout << "*";
    }
    std::cout << "\n";
    return 0;
}