#include "linklist.h"

bool  LinkList::incrementFrequency(string word)
{
    node *temp = headptr;
    while (temp != nullptr)
    {
        if (word.compare(temp->word) == 0)
        {
            temp->frequencyCount = temp->frequencyCount + 1;
            return true;
        }
        else
            temp = temp->next;
            
    }
    return false;
}

void  LinkList::print(ostream &out)
{
    node *temp = headptr;
    int max = getMaxFrequency();
    bool header = true;
    int count = 0;
    while (max != 0)
    {
        temp = headptr;
        header = true;
        while (temp != nullptr)
        {
            if (temp->frequencyCount == max){
                if (header)
                {
                    out << "\n**********************************************************" << endl <<
                    "\t\t Frequency of " << max << endl <<
                    "**********************************************************" << endl;
                    header = false;
                }
                if (count == 3)
                {
                    out << temp->word << endl;
                    count = 0;
                }
                else
                {
                    out << temp->word << "\t";
                    count++;
                }
            }
            temp = temp->next;
        }
        max--;
    }
}

bool LinkList::insert(string word) 
{
    node *temp = new node;
    node *temp2;
    temp->frequencyCount = 1;
    temp->word = word;
    temp->next = nullptr;

    if (headptr == nullptr)
    {
        headptr = temp;
        return true;
    }
    else 
    {
        temp2 = headptr;
        while (temp2->next != nullptr)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        return true;
    }
}