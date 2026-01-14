#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdint>

using namespace std;

int main(void)
{
    uint64_t t;
    vector<uint64_t> n;
    vector<vector<uint64_t>> p;
    uint64_t temp;
    int64_t l = 0;
    int64_t r = 0;
    uint64_t k = 0;
    vector<uint64_t> output;
    vector<string> out_string;


    cin >> t;
    n.resize(t);
    p.resize(t);
    output.resize(t);
    out_string.resize(t);

    for(uint64_t index = 0; index < t; index ++)
    {
        cin >> n[index];

        for(uint64_t arr_index = 0; arr_index < n[index]; arr_index ++)
        {
            cin >> temp;
            p[index].push_back(temp);
        }
    }

    for(uint64_t index = 0; index < t; index ++)
    { 
        sort(p[index].begin(), p[index].end());
        k = 0;

        for(uint64_t k_index = 0; k_index < n[index]; k_index ++)
        {
            k ++;
            r = n[index] - 1;
            l = r - k;

            // cout << "r = " << r << endl;
            // cout << "l = " << l << endl;

            while(r > l)
            {
                p[index][r] --;
                r --;
            }
        }

        for(uint64_t k_index = 0; k_index < n[index]; k_index ++)
        {
            output[index] += p[index][k_index];
        }

    }

    for(uint64_t index = 0; index < t; index ++)
    {
        if(output[index] == 0)
        {
            out_string[index] = "YES";
        }
        else
        {
            out_string[index] = "NO";
        }
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        cout << out_string[index] << endl;
    }



    return 0;
}



