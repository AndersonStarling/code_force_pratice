/* link: https://codeforces.com/problemset/problem/1843/B */
#include <iostream>
#include <vector>
 
using namespace std;
 
int main(void)
{
    uint64_t t;
    vector<uint64_t> n;
    vector<vector<int64_t>> arr;
    uint64_t temp;
    uint64_t ptr_1;
    uint64_t ptr_2;
    vector<uint64_t> oper_num;
    vector<uint64_t> sum;
    uint64_t l = 0;
    uint64_t r = 0;
    bool lower_zero_in = false;
 
    cin >> t;
    n.resize(t);
    arr.resize(t);
    oper_num.resize(t, 0);
    sum.resize(t, 0);
 
    for(uint64_t index = 0; index < t; index ++)
    {
        cin >> n[index];
        for(uint64_t index_arr = 0; index_arr < n[index]; index_arr ++)
        {
            cin >> temp;
            arr[index].push_back(temp);
        }
    }
 
    for(uint64_t index = 0; index < t; index ++)
    {
        lower_zero_in = false;
        for(uint64_t arr_index = 0; arr_index < n[index]; arr_index ++)
        {
            if(arr[index][arr_index] == 0)
            {
                continue;
            }
 
            if(arr[index][arr_index] < 0 && lower_zero_in == false)
            {
                lower_zero_in = true;
                oper_num[index] ++; 
            }
 
            if(arr[index][arr_index] > 0)
            {
                lower_zero_in = false;
            }
        }
    }
 
    for(uint64_t index = 0; index < t; index ++)
    {
        for(uint64_t arr_index = 0; arr_index < n[index]; arr_index ++)
        {
            if(arr[index][arr_index] < 0)
            {
                arr[index][arr_index] *= -1;
            }
            sum[index] += arr[index][arr_index];
        }
    }
 
    for(uint64_t index = 0; index < t; index ++)
    {
        cout << sum[index] << " " << oper_num[index] << endl;
    }
 
    return 0;
}