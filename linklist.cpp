/*************************************************************************//**
 * @file
 *****************************************************************************/

#include "linklist.h"

LinkList::LinkList()
{
    headptr = nullptr;
}

LinkList::~LinkList()
{
    node *temp = headptr;
    node *temp2 = headptr;
    while (temp2 != nullptr)
    {
        temp2 = temp->next;
        delete temp;
        temp = temp2;

    }
}

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

/**************************************************************************//**
* @author Alexander Crawford
*
* @par Description:
* This function takes in a word and searches the list for the word.  If the 
* word is found the function will return true, else the function returns
* false.  
*
* @param[in]     word - a word to search for.
*
* @returns true if the word is found
* @returns false if the word is not found
*****************************************************************************/
 bool LinkList::find(string word)
 {
	 node *temp = headptr; 

	 while (temp != nullptr)
	 {
		 if (word.compare(temp->word) == 0)
		 {
			 return true;
		 }
		 else
			 temp = temp->next;

	 }
	 return false;
 }

 /**************************************************************************//**
* @author Alexander Crawford
*
* @par Description:
* This function will go through the list of words and count the amount
* of words in the list.  The function will then return count when it is 
* finished.  
*
*
* @returns count - the number of words in the list.  
*****************************************************************************/
 int LinkList::size()			 
 {								 
	 node *temp = headptr;	
	 int count = 0;

	 while (temp != nullptr)
	 {
		 count++;
		 temp = temp->next;
	 }

	 return count;
 }

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