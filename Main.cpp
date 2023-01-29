#include <bits/stdc++.h>
#include "SkipListSearch.cpp"
using namespace std;
int main()
{
    Node obj(20);
    obj.Insert(10);
    obj.Insert(20);
    obj.Insert(30);
    obj.PrintList();
    cout << obj.SearchElement(20) << endl;
    cout << obj.SearchElement(25) << endl;
}