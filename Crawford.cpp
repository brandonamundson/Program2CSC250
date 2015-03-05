
#include "linklist.h"
//writing find and size
LinkList::LinkList()
{
	headptr = nullptr;
}

LinkList::~LinkList()
{
	//destructor if anything needs to happen
}
 bool LinkList::find(string word)
 {
	 node *temp = nullptr;

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

 /*int LinkList::size()			 // commented this out to give the people above me a chance to finish up 
 {								 // insert and remove and test without this causing issues. 
	 node *temp = nullptr;		 // go ahead and remove this if you wish to test and such 	
	 int count = 0;

	 while (temp != nullptr)
	 {
		 count++;
		 temp = temp->next;
	 }

	 return count;
 }*/