/* link: https://codeforces.com/problemset/problem/2154/A */

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

using namespace std;

int main(void)
{
    uint64_t t; /* number test case */
    vector<uint64_t> n; /* array len */
    vector<uint64_t> k; /* index searched */
    vector<string> s;
    uint64_t loop_iter = 0;
    bool have_1 = false;
    int64_t loop = 0;
    int64_t r = 0;
    vector<uint64_t> output;

    cin >> t;
    n.resize(t);
    k.resize(t);
    s.resize(t);
    output.resize(t, 0);

    for(uint64_t index = 0; index < t; index ++)
    {
        cin >> n[index] >> k[index];
        cin >> ws;
        getline(cin, s[index]);
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        if(s[index][0] == '1')
        {
            output[index] ++;
        }

        loop = 0;
        r = 0;
        have_1 = false;

        for(uint64_t string_index = 1; string_index < n[index]; string_index ++)
        {
            loop = (k[index] - 1);
            r = string_index - 1;

            have_1 = false;
            if(s[index][string_index] == '1')
            {
                while(loop > 0 && r >= 0)
                {
                    if(s[index][r] == '1')
                    {
                        have_1 = true;
                    }

                    loop --;
                    r --;
                }

                if(have_1 == false)
                {
                    output[index] ++;
                }
            }
        }

    }

    for(uint64_t index = 0; index < t; index ++)
    {
        cout << output[index] << endl;
    }

    return 0;
}







