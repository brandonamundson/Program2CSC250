#include "linklist.h"
#include <algorithm>

bool openFiles(char *argv[], ifstream &fin, ofstream &fout);
string removePunc(string temp);

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
                    list.insert(temp); //Call insert only if the increment fails because the word doesnt exist yet
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

string removePunc(string temp)
{
    unsigned int i;
    int size;
    size = temp.size();
    //transform(temp.begin(), temp.end(), temp.begin(), tolower);
    for (i = size; i > 0; i--)
    {
        temp[i] = tolower(temp[i]);
        if (isalnum(temp[i]) || temp[i] == 39)
        {

        }
        else 
        {
            temp.erase(i, 1);
            //size = temp.size();
        }

    }
    return temp;
}