#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    uint64_t t; /* number test case */
    vector<uint64_t> n;
    vector<vector<int64_t>> arr;
    uint64_t temp;
    uint64_t l = 0;
    uint64_t r = 0;
    vector<uint64_t> output_oper;
    vector<uint64_t> output_sum;

    cin >> t;
    n.resize(t);
    arr.resize(t);
    output_oper.resize(t, 0);
    output_sum.resize(t, 0);

    for(uint64_t index = 0; index < t; index ++)
    {
        cin >> n[index];

        for(uint64_t arr_index = 0; arr_index < n[index]; arr_index ++)
        {
            cin >> temp;
            arr[index].push_back(temp);
        }
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        l = 0;
        r = l + 1;
        while(r < n[index])
        {
            if(arr[index][l] < 0)
            {
                output_oper[index] ++;
                arr[index][l] *= -1;
            }

            if(arr[index][r] > 0)
            {
                l = r + 1;
                r = l;
                if(arr[index][l] < 0)
                {
                    arr[index][l] *= -1;
                    output_oper[index] ++;
                }
            }

            r ++;
        }
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        for(uint64_t arr_index = 0; arr_index < n[index]; arr_index ++)
        {
            output_sum[arr_index] += arr[index][arr_index];
        }
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        cout << output_sum[index] << " " << output_oper[index] << endl;
    }

    return 0;
}






