/* link: https://codeforces.com/problemset/problem/1972/A */
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    uint64_t t; /* number test case */
    vector<uint64_t> n; /* array len */
    vector<vector<uint64_t>> a;
    vector<vector<uint64_t>> b;
    uint64_t ptr_a = 0;
    uint64_t ptr_b = 0;
    uint64_t temp;
    vector<uint64_t> output;

    cin >> t;
    n.resize(t);
    a.resize(t);
    b.resize(t);
    output.resize(t);

    for(uint64_t index = 0; index < t; index ++)
    {
        cin >> n[index];

        for(uint64_t arr_index = 0; arr_index < n[index]; arr_index ++)
        {
            cin >> temp;
            a[index].push_back(temp);
        }

        for(uint64_t arr_index = 0; arr_index < n[index]; arr_index ++)
        {
            cin >> temp;
            b[index].push_back(temp);
        }
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        ptr_a = 0;
        ptr_b = 0;

        // cout << "index = " << index << endl;

        while(ptr_a < n[index])
        {
            if(a[index][ptr_a] > b[index][ptr_b])
            {
                int64_t index_progress = n[index] - 1;
                while(index_progress > ptr_a)
                {
                    // cout << "index_progress = " << index_progress << endl;
                    a[index][index_progress] = a[index][index_progress - 1];
                    index_progress --;
                }

                output[index] ++;
                a[index][ptr_a] = b[index][ptr_b];
            }

            ptr_a ++;
            ptr_b ++;
        }
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        cout << output[index] << endl;
    }

    return 0;
}


