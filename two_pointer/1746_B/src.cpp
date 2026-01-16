#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    uint64_t t; /* number test case */
    vector<uint64_t> n;
    vector<vector<uint64_t>> a;
    uint64_t l = 0;
    uint64_t r = 0;
    vector<uint64_t> output;
    uint64_t temp;

    cin >> t;
    n.resize(t);
    a.resize(t);
    output.resize(t, 0);

    for(uint64_t index = 0; index < t; index ++)
    {
        cin >> n[index];

        for(uint64_t string_index = 0; string_index < n[index]; string_index ++)
        {
            cin >> temp;
            a[index].push_back(temp);
        }
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        l = 0;
        r = n[index] - 1;

        while(l < r)
        {
            // cout << "DEBUG" << endl;
            // cout << "l = " << l << endl;
            // cout << "r = " << r << endl;
            // cout << "a[index][l] = " << a[index][l] << endl;
            // cout << "a[index][r] = " << a[index][r] << endl;
            // cout << "DEBUG" << endl;
    
            if(a[index][l] == 1 && a[index][r] == 0)
            {
                output[index] ++;
                l ++;
                r --;
            }
            else if(a[index][l] == 1 && a[index][r] == 1)
            {
                // cout << "DEBUG_11" << endl;
                r --;
            }
            else if(a[index][l] == 0 && a[index][r] == 0)
            {
                l ++;
            }
            else
            {
                l ++;
                r --;
            }
        }
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        cout << output[index] << endl;
    }

    return 0;
}

