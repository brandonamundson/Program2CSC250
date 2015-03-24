
#include "linklist.h"
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