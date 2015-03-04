#include "linklist.h"

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