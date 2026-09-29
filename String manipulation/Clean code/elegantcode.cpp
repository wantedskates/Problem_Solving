

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string source;
    bool block = 0;
    while (getline(cin, source))
    {
        bool x = false;
        if (source.size() == 0 || source == " ") // this checks whether the line is a space or not
        {
            continue;
        }

        for (int i = 0; i < source.size(); i++)
        {
            if (source[i] == '/' && source[i + 1] == '/' && !block)
            {
                break;
            }
            else if (source[i] == '/' && source[i + 1] == '*')
            {
                i++;
                block = true;
            }
            else if (source[i] == '*' && source[i + 1] == '/' && block)
            {
                i++;
                block = false;
            }
            else if (!block)
            {
                cout << source[i];
                x = true;
            }
        }

        if (x && !block)
            cout << endl;
    }
}
