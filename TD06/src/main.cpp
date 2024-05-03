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

    std::cout << "Affichage de la référence vers le pointeur du nœud le plus à gauche de l'arbre binaire :" << std::endl;
    Node *most_left = root->most_left(root);
    std::cout << most_left << " : " << most_left->value << std::endl;

    std::cout << "Suppression du nœud 5 :" << std::endl;
    root->remove(root, 15);
    pretty_print_left_right(*root);

    std::cout << "Suppression de l'arbre :" << std::endl;
    root->delete_tree(root);
    pretty_print_left_right(*root);

    return 0;
}