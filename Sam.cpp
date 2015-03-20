#include "linklist.h"

/**************************************************************************//**
 * @author Samuel Patzer
 *
 * @par Description:
 * This function gets in a word and then searchs for the word in the list. If
 * the word is found it will increment the frequency by one and return true.
 * If the word is not found it will return false.
 *
 * @param[in]     word - a word to search for and increment the frequency of.
 *
 * @returns true if the word is found and it increases the frequency by one
 * @returns false if the word is not found
 *****************************************************************************/
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

/**************************************************************************//**
 * @author Samuel Patzer
 *
 * @par Description:
 * This function print the list out to an output file provided by the user.
 * It also formats and addes headers to each frequency to easily read the list.
 *
 * @param[in, out]     out - the output file provided by the user
 *
 *****************************************************************************/

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
        count = 0;
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