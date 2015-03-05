
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

 int LinkList::size()
 {
	 node *temp = nullptr;
	 int count = 0;

	 while (temp != nullptr)
	 {
		 count++;
		 temp->next;
	 }

	 return count;
 }