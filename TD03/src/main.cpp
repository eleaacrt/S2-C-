#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <charconv>
#include <system_error>
#include <cctype>

// séparer les éléments(mots) de la chaîne de caractères en utilisant les espaces comme séparateurs
std::vector<std::string> split_string(std::string const &s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

// Écrire une fonction qui prends une chaîne de caractères et permet de dire si celle-ci représente un nombre flottant ou non. On utilisera le prototype suivant:
bool is_floating(std::string const &s)
{
    for (int i{0}; i < s.size(); i++)
    {
        if (s[i] == '.' || std::isdigit(s[i]))
        {
            return true;
        }
    }
    return false;
}

// Écrire une fonction qui prend en paramètre un vecteur de chaînes de caractères représentant les tokens de l'expression en NPI, et qui retourne le résultat de l'expression.
float npi_evaluate(std::vector<std::string> const &tokens)
{
    std::stack<float> stack;
    for (int i{0}; i < tokens.size(); i++)
    {
        if (is_floating(tokens[i]))
        {
            float token{std::stof(tokens[i])};
            stack.push(token);
        }
        else
        {
            float rightOperand{stack.top()};
            stack.pop();
            float leftOperand{stack.top()};
            stack.pop();
            if (tokens[i] == "+")
            {
                float result{leftOperand + rightOperand};
                stack.push(result);
            }
            else if (tokens[i] == "-")
            {
                float result{leftOperand - rightOperand};
                stack.push(result);
            }
            else if (tokens[i] == "*")
            {
                float result{leftOperand * rightOperand};
                stack.push(result);
            }
            else if (tokens[i] == "/")
            {
                float result{leftOperand / rightOperand};
                stack.push(result);
            }
        }
    }
    return stack.top();
}

int main()
{
    // exercice 1
    // On va pouvoir se servir d'une pile(std::stack) pour évaluer une expression en NPI.

    std::string user_npi;
    std::cout << "Entrez une expression en NPI : ";
    std::getline(std::cin, user_npi);

    std::vector<std::string> new_npi = split_string(user_npi);
    std::cout << npi_evaluate(new_npi) << std::endl;

    return 0;
}