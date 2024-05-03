#include <iostream>
#include <string>
#include <vector>
#include "./node.hpp"

Node *create_node(int value)
{
    Node *node = new Node;
    node->value = value;
    return node;
}

bool Node::is_leaf() const
{
    return left == nullptr && right == nullptr;
}

void Node::insert(int v)
{
    if (v < value)
    {
        if (left)
        {
            left->insert(v);
        }
        else
        {
            left = create_node(v);
        }
    }
    else
    {
        if (right)
        {
            right->insert(v);
        }
        else
        {
            right = create_node(v);
        }
    }
}

int Node::height() const
{
    int left_height = left ? left->height() : 0;
    int right_height = right ? right->height() : 0;
    return 1 + std::max(left_height, right_height);
}

void Node::delete_childs()
{
    if (left)
    {
        left->delete_childs();
        delete left;
        left = nullptr;
    }
    if (right)
    {
        right->delete_childs();
        delete right;
        right = nullptr;
    }
}

void Node::display_infixe() const
{
    if (left)
    {
        left->display_infixe();
    }
    std::cout << value << std::endl;
    if (right)
    {
        right->display_infixe();
    }
}

std::vector<Node const *> Node::prefixe() const
{
    std::vector<Node const *> nodes;
    nodes.push_back(this);
    if (left)
    {
        auto left_nodes = left->prefixe();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }
    if (right)
    {
        auto right_nodes = right->prefixe();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    return nodes;
}

Node *&Node::most_left(Node *&node)
{
    if (left)
    {
        return left->most_left(left);
    }
    return node;
}

bool Node::remove(Node *&node, int value)
{
    if (node == nullptr)
    {
        return false;
    }
    if (value < node->value)
    {
        return remove(node->left, value);
    }
    if (value > node->value)
    {
        return remove(node->right, value);
    }
    if (node->left == nullptr)
    {
        Node *right = node->right;
        delete node;
        node = right;
        return true;
    }
    if (node->right == nullptr)
    {
        Node *left = node->left;
        delete node;
        node = left;
        return true;
    }
    Node *&most_left = node->right->most_left(node->right);
    node->value = most_left->value;
    return remove(node->right, most_left->value);
}

void Node::delete_tree(Node *node)
{
    if (node)
    {
        node->delete_childs();
        delete node;
        node = nullptr;
    }
}
