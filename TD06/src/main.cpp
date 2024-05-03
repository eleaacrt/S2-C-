#include <iostream>
#include <string>
#include <vector>
#include "node.hpp"

// permet d'afficher une représentation ASCII dans la console d'un arbre binaire :

void pretty_print_left_right(Node const &node, std::string const &prefix, bool is_left)
{
    if (node.right)
    {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left)
    {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const &node)
{
    pretty_print_left_right(node, "", true);
}

int main()
{
    Node *root = create_node(10);

    root->insert(5);
    root->insert(15);
    root->insert(2);
    root->insert(7);
    root->insert(12);
    root->insert(17);


    std::cout << "Affichage de l'arbre :" << std::endl;
    pretty_print_left_right(*root);

    std::cout << "Hauteur de l'arbre : " << root->height() << std::endl;

    std::cout << "Affichage infixe de l'arbre :" << std::endl;
    root->display_infixe();
    
    std::cout << "Affichage préfixe de l'arbre :" << std::endl;
    std::vector<Node const *> nodes = root->prefixe();
    for (Node const *node : nodes)
    {
        std::cout << node->value << std::endl;
    }

    return 0;
}