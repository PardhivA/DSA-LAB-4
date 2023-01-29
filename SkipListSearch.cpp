#include <bits/stdc++.h>
#include "SkipListSearch.h"
using namespace std;

#define MAXI 2147483647

Node::Node(int waste)
{
    this->head = new Node();
    this->head->data = INT_MIN;
    cout << this->head->data << endl;
    Node *temp = new Node();
    this->head->ArrNodes.push_back(temp);
    this->head->ArrNodes[0]->data = INT_MAX;
    cout << this->head->ArrNodes[0]->data << endl;
    this->level = 0;
}
Node::Node()
{
}

void Node::CreateNode(int giv_data, Node *Back, int cur_level)
{
    Node *new_temp = new Node(); // 1->3 1->2->3
    new_temp->data = giv_data;

    Node *temp = Back->ArrNodes[cur_level];
    Back->ArrNodes[cur_level] = new_temp;
    new_temp->ArrNodes.push_back(temp);
}

void Node::LinkNode(Node *Back, Node *New_link, int cur_level)
{
    Node *temp = Back->ArrNodes[cur_level];
    Back->ArrNodes[cur_level] = New_link;
    New_link->ArrNodes.push_back(temp);
}

void Node::Insert(int giv_data)
{
    int cur_level = this->level;
    cout << cur_level << "HI" << endl;
    // int size_of_ArrNodes = this->ArrNodes.size();
    // cout << size_of_ArrNodes << endl;
    Node *cur_node = this->head;
    cout << cur_node->data << "Testing" << endl;
    // Node *level_node;
    stack<Node *> level_nodes;
    while (cur_level >= 0)
    {
        level_nodes.push(cur_node);
        while (giv_data > cur_node->ArrNodes[cur_level]->data)
        {
            cur_node = cur_node->ArrNodes[cur_level];
        }
        cur_level--;
    }

    cur_level = 0;

    CreateNode(giv_data, cur_node, cur_level);
    cur_node = cur_node->ArrNodes[cur_level];
    srand(time(0));
    int random = rand();
    cur_level = 1;
    while (random / (float)MAXI > 0.5 && level_nodes.size() != 0)
    {
        LinkNode(level_nodes.top(), cur_node, cur_level++);
        level_nodes.pop();
    }
    level = cur_level;
    cout << level << "Check level" << endl;
}

bool Node::SearchElement(int giv_data)
{

    Node *cur_node = this->head;
    int cur_level = level;
    // int size_of_ArrNodes = cur_node->ArrNodes.size();
    // Node *level_node;
    // cur_node->data = INT_MIN;
    // stack<Node *> level_nodes;
    while (cur_level >= 0)
    {
        // level_nodes.push(cur_node);
        while (giv_data >= cur_node->ArrNodes[cur_level]->data)
        {
            cur_node = cur_node->ArrNodes[cur_level];
        }
        cur_level--;
    }
    cur_level++;
    cout << cur_node->data << "current data " << endl;
    if (giv_data == cur_node->data)
        return true;
    else
        return false;
}
void Node::PrintList()
{
    Node *cur_node = this->head;
    while (cur_node->data != INT_MAX)
    {
        cout << cur_node->data << endl;
        cur_node = cur_node->ArrNodes[0];
    }
}