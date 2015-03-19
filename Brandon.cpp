#include "linklist.h"


/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * This is the remove function of the program.  It is used when needing to
 * delete a specific word from the list.
 *
 * @param[in]        word - the word that is to be removed from the list.
 *
 * @returns true - successfully deleted specified word.
 * @returns false - word could not be found in list and could not be deleted.
 *
 ******************************************************************************/
bool LinkList::remove(string word)
{
    node *temp = nullptr;
    node *prev = nullptr;
    prev = temp;
    temp = headptr;

    while (temp != nullptr)
    {
        if (word.compare(temp->word) == 0)
        {
            prev->next = temp->next;
            delete temp;
            return true;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return false;

}


/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * This is the function that returns the maximum frequency of any word that is 
 * located in the list.  It is called by the print function to output the
 * words in order of frequency as they appear in the list.
 *
 *
 * @returns max - the maximum frequency of the words in the list.
 *
 ******************************************************************************/
int LinkList::getMaxFrequency()
{
    node *curr = headptr;
    int max = 0;

    while (curr != nullptr)
    {
        if (curr->frequencyCount >= max)
        {
            max = curr->frequencyCount;
            curr = curr->next;
        }
        else
            curr = curr->next;
    }
    return max;
}
