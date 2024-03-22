#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <charconv>
#include <system_error>
#include <cctype>

enum class Operator
{
    ADD,
    SUB,
    MUL,
    DIV,
    OPEN_PAREN,
    CLOSE_PAREN
};

enum class TokenType
{
    OPERATOR,
    OPERAND
};

struct Token
{
    TokenType type;
    float value;
    Operator op;
};

float npi_evaluate(std::vector<std::string> const &tokens);
float npi_evaluateV2(std::vector<Token> const &tokens);
std::vector<std::string> split_string(std::string const &s);
bool is_floating(std::string const &s);

// Créer deux fonctions (surchargées) qui permettent de construire la structure Token à partir d'un nombre flottant ou de la valeur de l’énumération Operator.

Token make_token(float value)
{
    return Token{
        TokenType::OPERAND,
        value,
        Operator::ADD};
}

Token make_token(Operator op)
{
    return Token{
        TokenType::OPERATOR,
        0.0f,
        op};
}

std::vector<Token> tokenize(std::vector<std::string> const &words)
{
    std::vector<Token> tokens;
    for (auto it{words.begin()}; it != words.end(); it++)
    {
        if (is_floating(*it))
        {
            tokens.push_back(make_token(std::stof(*it)));
        }
        else
        {
            if (*it == "+")
            {
                tokens.push_back(make_token(Operator::ADD));
            }
            else if (*it == "-")
            {
                tokens.push_back(make_token(Operator::SUB));
            }
            else if (*it == "*")
            {
                tokens.push_back(make_token(Operator::MUL));
            }
            else if (*it == "/")
            {
                tokens.push_back(make_token(Operator::DIV));
            }
            else if (*it == "(")
            {
                tokens.push_back(make_token(Operator::OPEN_PAREN));
            }
            else if (*it == ")")
            {
                tokens.push_back(make_token(Operator::CLOSE_PAREN));
            }
        }
    }
    return tokens;
}

// Créer une nouvelle fonction npi_evaluate qui utilise cette fois un vecteur de Token au lieu de manipuler directement des chaînes de caractères.
float npi_evaluateV2(std::vector<Token> const &tokens)
{
    std::stack<float> stack;
    for (auto it{tokens.begin()}; it != tokens.end(); it++)
    {
        if (it->type == TokenType::OPERAND)
        {
            stack.push(it->value);
        }
        else
        {
            float rightOperand{stack.top()};
            stack.pop();
            float leftOperand{stack.top()};
            stack.pop();
            if (it->op == Operator::ADD)
            {
                float result{leftOperand + rightOperand};
                stack.push(result);
            }
            else if (it->op == Operator::SUB)
            {
                float result{leftOperand - rightOperand};
                stack.push(result);
            }
            else if (it->op == Operator::MUL)
            {
                float result{leftOperand * rightOperand};
                stack.push(result);
            }
            else if (it->op == Operator::DIV)
            {
                float result{leftOperand / rightOperand};
                stack.push(result);
            }
            else if (it->op == Operator::OPEN_PAREN)
            {
                stack.push(leftOperand);
                stack.push(rightOperand);
            }
            else if (it->op == Operator::CLOSE_PAREN)
            {
                stack.pop();
            }
        }
    }
    return stack.top();
}

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
    std::string user_npi_V2{user_npi};


    // exercice 1
    std::vector<std::string> new_npi = split_string(user_npi);
    std::cout << "exercice 1 : " << npi_evaluate(new_npi) << std::endl;

    // exercice 2
    std::vector<Token> new_npi_V2 = tokenize(split_string(user_npi_V2));
    std::cout << "exercice 2 : " << npi_evaluateV2(new_npi_V2) << std::endl;


    return 0;
}