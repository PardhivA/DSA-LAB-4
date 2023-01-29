#include <bits/stdc++.h>
using namespace std;
class Node
{
private:
public:
    int data;
    int level;
    Node *head;
    vector<Node *> ArrNodes;
    void CreateNode(int data, Node *Back, int cur_level);
    void LinkNode(Node *Back, Node *New_link, int cur_level);
    void Insert(int data);
    Node(int waste);
    Node();
    bool SearchElement(int data);
    void PrintList();
};
