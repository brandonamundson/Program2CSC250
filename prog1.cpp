/*************************************************************************//**
 * @file 
 *
 * @mainpage Program 2 Part 1 - Word Frequency - Linked Lists
 * 
 * @section course_section Course Information 
 *
 * @author Samuel Patzer, Cody Ortega, Brandon Amudson, Alex Crawford, 
 * 
 * @date 2/27/2015
 * 
 * @par Professor: 
 *         Roger Schrader
 * 
 * @par Course: 
 *         CSC250 - M0001 - 11:00AM
 * 
 * @par Location: 
 *         McLaury - Room 204W
 *
 * @section program_section Program Information 
 * 
 * @details A program to help book editors and authors to view the Frequency of
 * the words they used in their short stories. The editors beleive that truly
 * good short stories use very few words over and over. So using the program 
 * will help the editors will prove that this is true or not and the authors can
 * use it to avoid using the same word to many times. The program will take in a
 * short story and then will read in word by word and remove puncuation and check
 * to see if the word exists and if it does it increases the frequency otherwise
 * it adds the word to the list. Once it parses the document it will output a 
 * list with the frequency and then words with that frequency.
 *
 *
 * @section compile_section Compiling and Usage 
 *
 * @par Compiling Instructions: 
 *      None.
 * 
 * @par Usage: 
   @verbatim  
   c:\> prog1.exe  input.txt output.txt
                   input.txt - a short story or paragraph
                   output.txt - an ouput text that gives the frequency of a word
   @endverbatim 
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 * 
 * 
 * @par Modifications and Development Timeline: 
   @verbatim 
   Date          Modification 
   ------------  -------------------------------------------------------------- 
   Mar  4, 2015  First team meeting
   Mar 17, 2015  Second team meeting
   Mar 24, 2015  Third team meeting
   @endverbatim
 *
 *****************************************************************************/

#include "linklist.h"
#include <algorithm>

bool openFiles(char *argv[], ifstream &fin, ofstream &fout);
string removePunc(string temp);

/**************************************************************************//**
 * @author Samuel Patzer
 *
 * @par Description:
 * Main function that is called first when the program boots. It first checks
 * to make sure that there is a valid amount of arguments and then opens the
 * files provided by the user. After the file succesfully opens it reads a 
 * word in and removes the puncuation and then checks to see if it can
 * increment the frequency of the that word. If that increment fails it will
 * insert the word. It will do this for all the words in the file provided 
 * then it will output the list out to a file.
 *
 * @param[in]      argc - a count of the command line arguments used to start
 *                        the program.
 * @param[in]     argv - a 2d character array of each argument.  Each token
 *                        occupies one line in the array.
 *
 * @returns 0 program ran successful.
 * @returns 1 the program fails because the command is wrong.
 * @returns 2 the program fails because the program couldnt open a file
 *
 *****************************************************************************/
int main(int argc, char *argv[])
{
    ifstream fin;
    ofstream fout;
    LinkList list;
    string temp;
    if (argc == 3)
    {
        if (openFiles(argv, fin, fout))
        {
            while (fin >> temp)
            {
                temp = removePunc(temp);
                if (!list.incrementFrequency(temp))
                {
                    list.insert(temp);
                }
            }
            list.print(fout);
        }
        else
            return 2;
    }
    else 
    {
        cout << "Invalid number of commands" << endl;
        return 1;
    }
    return 0;
}

/**************************************************************************//**
 * @author Samuel Patzer
 *
 * @par Description:
 * This function gets in a word and then searchs for the word in the list. If
 * the word is found it will increment the frequency by one and return true.
 * If the word is not found it will return false.
 *
 * @param[in]      argv - array of characters containing the file names
 * @param[out]     fin - input file provided by the user
 * @param[out]     fout - output file provided by the user
 *
 * @returns true if the files are succesfully opened 
 * @returns false if the files are not successfully opened
 *****************************************************************************/
bool openFiles(char *argv[], ifstream &fin, ofstream &fout)
{
    fin.open(argv[1]);
    if (!fin)
    {
        cout << "Failed to open input file" << endl;
        return false;
    }
    fout.open(argv[2]);
    if (!fout)
    {
        cout << "Failed to open output file" << endl;
        return false;
    }
    return true;
}

/**************************************************************************//**
 * @author Samuel Patzer
 *
 * @par Description:
 * This function removes the puncuation from the string and then returns the
 * string with no puncuation.
 *
 * @param[in]      temp - a word containing puncuation.
 *
 * @returns a string containing no puncuation.
 *****************************************************************************/
string removePunc(string temp)
{
    int i;
    int size;
    size = temp.size();
    //transform(temp.begin(), temp.end(), temp.begin(), tolower);
    for (i = 0; i < size; i++)
    {
        temp[i] = tolower(temp[i]);
        if (isalnum(temp[i]) || temp[i] == 39)
        {

        }
        else 
        {
            temp.erase(i, 1);
            size = temp.size();
            i = i - 1;
        }

    }
    return temp;
}