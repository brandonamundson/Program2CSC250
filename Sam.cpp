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
    int max = LinkList::getMaxFrequency();
    bool header = true;
    int count = 0;
    /*
    while (temp != nullptr)
    {
        out << temp->word << " - " << temp->frequencyCount << endl;
        temp = temp->next;
    }
    */
    
    //All formated code ready to go once getMaxFrequency is coded also uncomment int max!
    while (max != 0)
    {
        header = true;
        while (temp != nullptr)
        {
            if (temp->frequencyCount == max){
                if (header)
                {
                    out << "**********************************************************" << endl <<
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