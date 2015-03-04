#include <iostream>
#include <fstream>
#include <string>
#ifndef __FUNCTIONS__H__
#define __FUNCTIONS__H__

using namespace std;

class LinkList
{
public:
    LinkList();
    ~LinkList();

    bool insert(string word);
    bool remove(string word);
    bool find(string word);
    bool incrementFrequency(string word);
    bool isEmpty();
    int getMaxFrequency();
    int size();
    void print(ostream &out);

private:
    struct node
    {
        int frequencyCount;
        string word;
        node *next;
    };
    node *headptr;
};

#endif