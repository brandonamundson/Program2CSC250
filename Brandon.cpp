#include "linklist.h"

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


int LinkList::getMaxFrequency()
{
    node *curr = headptr;
    int max = 0;

    while (curr != nullptr)
    {
        if (curr->frequencyCount >= max)
        {
            max = curr->frequencyCount;
            curr->next;
        }
        else
            curr = curr->next;
    }
    return max;
}
