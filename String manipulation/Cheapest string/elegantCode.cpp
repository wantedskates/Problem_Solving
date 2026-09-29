

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string input;
    long long cost[26];
    cin >> input;
    for (int i = 0; i < 26; i++)
    {
        cin >> cost[i];
    }
    long long q = 0;

    for (int i = 0; i < input.size(); i++)
    {
        q = 0;
        if (input[i] == '?')
        {

            for (int j = i; j < input.size(); j++)
            {
                if (input[j] == '?')
                {
                    q++;
                }
                else
                {
                    break;
                }
            }

            if (q == input.size())
            {
                cout << 0 << endl;
                for (int j = 0; j < input.size(); j++)
                {
                    cout << "a";
                }
                return 0;
            }
            else
            {
                if (i == 0)
                {
                    long long min = INT_MAX, index;
                    for (int z = 0; z < (input[q] - 97) + 1; z++)
                    {
                        long long current = abs(cost[input[q] - 97] - cost[z]);
                        if (min > current)
                        {
                            min = current;
                            index = z;
                        }
                    }
                    char replace = index + 97;
                    for (int j = 0; j < q; j++)
                    {
                        input[j] = replace;
                    }

                    i += q;
                }
                else if (i + q == input.size())
                {
                    long long min = INT_MAX, index;
                    for (int z = 0; z < (input[i - 1] - 97) + 1; z++)
                    {
                        long long current = abs(cost[input[i - 1] - 97] - cost[z]);
                        if (min > current)
                        {
                            min = current;
                            index = z;
                        }
                    }
                    char replace = index + 97;

                    for (int j = i; j < q + i; j++)
                    {
                        input[j] = replace;
                    }

                    break;
                } // this ask whether the given '?' string is a tail or not
                else
                {
                    long long min = INT_MAX, index;
                    for (int x = 0; x < 26; x++)
                    {
                        long long current = abs(cost[input[i - 1] - 97] - cost[x]) + abs(cost[x] - cost[input[i + q] - 97]);
                        if (min > current)
                        {
                            min = current;
                            index = x;
                        }
                    }
                    char replace = index + 97;

                    for (int j = i; j < i + q; j++)
                    {
                        input[j] = replace;
                    }

                    i += q;
                }
            }
        }
    }



    // part 2 : calculating the sum

    long long sum = 0;
    for (int i = 0; i < input.size() - 1; i++)
    {
        sum += abs(cost[input[i] - 97] - cost[input[i + 1] - 97]);
    }

    cout << sum << endl;
    cout << input << endl;
}
