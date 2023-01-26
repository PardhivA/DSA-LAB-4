#include <bits/stdc++.h>
#include "SkipListSearch.h"
using namespace std;

#define MAXI 2147483647

Node::Node()
{
    this->data = INT_MIN;
    this->ArrNodes[0]->data = INT_MAX;
    this->level = 0;
}

void Node::CreateNode(int data, Node *Back, int cur_level)
{
    Node *new_temp = new Node;
    new_temp->data = data;
    Node *temp = Back->ArrNodes[cur_level];
    Back->ArrNodes[cur_level] = new_temp;
    new_temp->ArrNodes[cur_level] = temp;
}

void Node::LinkNode(Node *Back, Node *New_link, int cur_level)
{
    Node *temp = Back->ArrNodes[cur_level];
    Back->ArrNodes[cur_level] = New_link;
    New_link->ArrNodes[cur_level] = temp;
}

void Node::Insert(int giv_data, int level)
{
    int cur_level = level;
    int size_of_ArrNodes = ArrNodes.size();
    Node *cur_node = ArrNodes[size_of_ArrNodes - 1];
    Node *level_node;
    cur_node->data = INT_MIN;
    stack<Node *> level_nodes;
    while (cur_level >= 0)
    {
        level_nodes.push(cur_node);
        while (giv_data <= cur_node->ArrNodes[cur_level]->data)
        {
            cur_node = cur_node->ArrNodes[cur_level];
        }
        cur_level--;
    }

    CreateNode(giv_data, cur_node, cur_level);
    cur_node = cur_node->ArrNodes[cur_level];
    srand(time(0));
    int random = rand();
    cur_level = 1;
    while (random / (float)MAXI > 0.5)
    {
        LinkNode(level_nodes.top(), cur_node, cur_level++);
        level_nodes.pop();
    }
}