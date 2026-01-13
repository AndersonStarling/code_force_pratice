/* link: https://codeforces.com/problemset/problem/2025/A */
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

using namespace std;

int main(void)
{
    uint64_t q; /* number test case */
    vector<string> string_s;
    vector<string> string_t;
    uint64_t len_s = 0;
    uint64_t len_t = 0;
    uint64_t len_loop = 0;
    vector<uint64_t> output;
    uint64_t len_same = 0;

    cin >> q;
    cin >> ws;
    string_s.resize(q);
    string_t.resize(q);
    output.resize(q);

    for(uint64_t index = 0; index < q; index ++)
    {
        getline(cin, string_s[index]);
        cin >> ws;
        getline(cin, string_t[index]);
    }

    for(uint64_t index = 0; index < q; index ++)
    {
        len_s = string_s[index].length();
        len_t = string_t[index].length();
        len_same = 0;
        len_loop = 0;

        // cout << "----------------------" << endl;
        // cout << "index = " << index << endl;
        // cout << "len_s = " << len_s << endl;
        // cout << "len_t = " << len_t << endl;

        if(len_s < len_t)
        {
            len_loop = len_s;
        }
        else
        {
            len_loop = len_t;
        }

        for(uint64_t string_index = 0; string_index < len_loop; string_index ++)
        {
            if(string_s[index][string_index] == string_t[index][string_index])
            {
                output[index] ++;
                len_same ++;
            }
            else
            {
                break;
            }
        }

        if(len_same != 0)
        {
            output[index] ++;
        }

        // cout << "len_same = " << len_same << endl;

        for(uint64_t string_index = len_same; string_index < len_s; string_index ++)
        {
            output[index] ++;
        }

        for(uint64_t string_index = len_same; string_index < len_t; string_index ++)
        {
            output[index] ++;
        }

        // cout << "----------------------" << endl;
    }

    for(uint64_t index = 0; index < q; index ++)
    {
        cout << output[index] << endl;
    }


    return 0;
}















