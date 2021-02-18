#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;

int strcasestr(const char* bigStr, const char* searchStr);
char setUpperCase(char c1);

int main(int argc, char* argv[])
{
    ifstream myfile;
    string str1;
    string str2;
    int index = 0;
    
    if (argc == 3) // MODE 1 = string -> file SEARCH
    {
        myfile.open(argv[2], ios::in);

        if (!myfile)
        {
            cout << "File " << argv[2] << " not found!" << endl;
            return 0;
        }

        string line;
        while (getline(myfile, line))
        {
            const char* c1 = line.c_str();
            index = strcasestr(c1, argv[1]);

            if (index != -1)
                cout << line << endl; 
        }
    }
    else // MODE 2 = string -> string SEARCH
    {
        cout << "Give a string from which to search for: ";
        getline(cin, str1);
        cout << "Give search string: ";
        getline(cin, str2);

        const char* c1 = str1.c_str();
        const char* c2 = str2.c_str();

        index = strcasestr(c1, c2);

        if (index != -1)
            cout << "\"" << c2 << "\" found in \"" << c1 << "\" in position " << index;
        else
            cout << "\"" << c2 << "\" NOT found in \"" << c1 << "\"";
    }
}

int strcasestr(const char* bigStr, const char* searchStr)
{
    int i = 0;
    int u = 0;
    int match_counter = 0;

    while (bigStr[i] != '\0')
    {
        if (setUpperCase(bigStr[i]) == setUpperCase(searchStr[u]))
            u++;
        else
        {
            if (u) { u = 0; continue; }
            else u = 0;
        }

        if (u == strlen(searchStr))
            return ((i + 1) - strlen(searchStr));

        i++;
    }

    return -1;

}

char setUpperCase(char c1)
{
    if (c1 >= 'a' && c1 <= 'z')
        c1 = c1 - 32;

    return c1;
}
