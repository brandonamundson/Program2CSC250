/*************************************************************************//**
 * @file
 *****************************************************************************/

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

    /*!
    * @brief Holds word and frequency count
    */

    struct node
    {
        int frequencyCount; /*!< Frequency count */
        string word; /*!< Word of the node */
        node *next; /*!< Next word in the list*/
    };
    node *headptr;
};

#endif