/*************************************************************************//**
 * @file
 *****************************************************************************/
#include "linklist.h"


/**************************************************************************//** 
 * @author Cody Ortega
 * 
 * @par Description: 
 * insert word one into the list at ascending value and in the same nod gives 
 * it a frequency count that will be used later in a different function. 
 * 
 * 
 * @param[in]      word - word that will be inserted into the lsit
 * 
 * @returns true - if it inserted the words
 * @return  false - if it could not insert the words
 * 
 *****************************************************************************/

bool LinkList::insert(string word)
{
    node *temp = headptr;
    node *prev = nullptr; 
    node *new_node = nullptr;

    new_node = new(nothrow) node; // new nod that will go into the list
    if (new_node == nullptr)
    {
        return false;
    }

    new_node->word = word;
    new_node->frequencyCount = 1;
    new_node->next = nullptr;

    if (headptr == nullptr)
    {
        headptr = new_node;
        return true;
    }
    if (new_node->word <= headptr->word)
    {
        new_node->next = headptr;
        headptr = new_node;
        return true;
    }
    while (temp != nullptr && temp->word <= new_node->word )
    {
        prev = temp;
        temp = temp->next; 
    }
    new_node->next = temp;
    prev->next = new_node;
    return true;
}
/**************************************************************************//** 
 * @author Cody Ortega
 * 
 * @par Description: 
 *
 * checks to see if the list is empty by checking to see if headptr is empty
 * 
 * 
 * @returns true - if the list is empty
 * @returns false - If the list is not empty
 * 
 *****************************************************************************/

bool LinkList::isEmpty()
{
    if (headptr == nullptr)
        return true;
    return false;
}