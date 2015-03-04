#include "linklist.h"

bool openFiles(char *argv[], ifstream &fin, ofstream &fout);

int main(int argc, char *argv[])
{
    ifstream fin;
    ofstream fout;
    if (argc == 3)
    {
        if (openFiles(argv, fin, fout))
        {

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