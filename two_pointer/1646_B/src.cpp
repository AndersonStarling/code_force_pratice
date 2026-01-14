/* link: https://codeforces.com/contest/1646/problem/B */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main(void)
{
    uint64_t t; /* number test case */
    vector<uint64_t> n; /* array len */
    vector<vector<uint64_t>> a;
    uint64_t l = 0;
    uint64_t r = 0;
    uint64_t count_l = 0;
    uint64_t count_r = 0;
    uint64_t sum_l = 0;
    uint64_t sum_r = 0;
    uint64_t temp;
    vector<string> output;
 
    cin >> t;
    n.resize(t);
    a.resize(t);
    output.resize(t);
 
    for(uint64_t index = 0; index < t; index ++)
    {
        cin >> n[index];
 
        for(uint64_t array_index = 0; array_index < n[index]; array_index ++)
        {
            cin >> temp;
            a[index].push_back(temp);
        }
    }
 
    for(uint64_t index = 0; index < t; index ++)
    {
        sort(a[index].begin(), a[index].end());
        l = 0;
        r = a[index].size() - 1;
        count_l = 1;
        count_r = 1;
        sum_l = a[index][l];
        sum_r = a[index][r];
        output[index] = "NO";
        // cout << "sum_r = " << sum_r << endl;
        // cout << "sum_l = " << sum_l << endl;
 
        while(l < r)
        {
            // cout << "index = " << index << endl;
            // cout << "l = " << l << endl;
            // cout << "r = " << r << endl;
            // cout << "sum_r = " << sum_r << endl;
            // cout << "sum_l = " << sum_l << endl;
 
            if(sum_r > sum_l && count_l > count_r)
            {
                output[index] = "YES";
                break;
            }
            else if(sum_r > sum_l && count_l <= count_r)
            {
                l ++;
                sum_l += a[index][l];
                count_l ++;
            }
            else if(sum_r < sum_l)
            {
                r --;
                count_r ++;
                sum_r += a[index][r];
            }
            else if(sum_l == sum_r)
            {
                l ++;
                sum_l += a[index][l];
                count_l ++;
            }
 
            // cout << "----------------------" << endl;
        }
 
        // cout << "count_l = " << count_l << endl;
        // cout << "count_r = " << count_r << endl;
        // cout << "sum_r = " << sum_r << endl;
        // cout << "sum_l = " << sum_l << endl;
    }
 
    for(uint64_t index = 0; index < t; index ++)
    {
        cout << output[index] << endl;
    }
 
    return 0;
}