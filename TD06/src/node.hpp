#pragma once
#include <iostream>

struct Node
{
    int value;
    Node *left{nullptr};
    Node *right{nullptr};

    // créer un nœud contenant une valeur
    bool is_leaf() const;

    // insérer une valeur dans l'arbre
    void insert(int value);

    int height() const;

    void delete_childs();

    void display_infixe() const;

    std::vector<Node const *> prefixe() const;

    Node *&most_left(Node *&node);

    bool remove(Node*& node, int value);

    void delete_tree(Node* node);
};

Node *create_node(int value);
