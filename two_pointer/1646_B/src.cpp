#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
    uint64_t t; /* number test case */
    vector<uint64_t> n;
    uint64_t l = 0;
    uint64_t r = 0;
    vector<vector<uint64_t>> a;
    uint64_t temp;
    uint64_t sum_l = 0;
    uint64_t sum_r = 0;
    uint64_t count_l = 0;
    uint64_t count_r = 0;
    vector<string> output;

    cin >> t;
    n.resize(t);
    a.resize(t);
    output.resize(t);

    for(uint64_t index = 0; index < t; index ++)
    {
        cin >> n[index];

        for(uint64_t arr_index = 0; arr_index < n[index]; arr_index ++)
        {
            cin >> temp;
            a[index].push_back(temp);
        }
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        l = 0;
        r = a[index].size() - 1;
        sum_r = 0;
        sum_l = 0;
        output[index] = "NO";

        sort(a[index].begin(), a[index].end());
        sum_r += a[index][r];
        sum_l += a[index][l];
        count_l ++;
        count_r ++;

        while(l < r)
        {
            if(sum_r > sum_l && count_l <= count_r)
            {
                l ++;
                count_l ++;
                sum_l += a[index][l];
            }
            else if(sum_r < sum_l)
            {
                sum_r -= a[index][r];
                r --;
                sum_r += a[index][r]
                count_r ++;
            }
        }
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        cout << output[index] << endl;
    }

    return 0;
}



