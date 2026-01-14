/* link: https://codeforces.com/problemset/problem/2154/A */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    uint64_t t; /* number test case */
    vector<uint64_t> n; /* array len */
    vector<uint64_t> k; /* index searched */
    vector<string> s;
    uint64_t loop_iter = 0;

    cin >> t;
    n.resize(t);
    k.resize(t);
    s.resize(t);

    for(uint64_t index = 0; index < t; index ++)
    {
        cin >> n[index] >> k[index];
        cin >> ws;
        getline(cin, s[index]);
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        for(string_index = 0; string_index < n[index]; string_index ++)
        {
            loop_iter = string_index - 1;
            while(s[index][string_index] == 1 && loop_iter >= 0)
            {
                
            }
        }
    }



    return 0;
}







