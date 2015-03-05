#include "linklist.h"
//still need to do getMaxFrequency

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


