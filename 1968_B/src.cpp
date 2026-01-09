#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    uint64_t t; /* number test case */
    vector<uint64_t> n; /* len a */
    vector<uint64_t> m; /* len b */
    vector<string> string_a;
    vector<string> string_b;
    uint64_t ptr_a = 0;
    uint64_t ptr_b = 0;
    vector<uint64_t> output;


    cin >> t;
    n.resize(t);
    m.resize(t);
    string_a.resize(t);
    string_b.resize(t);
    output.resize(t, 0);

    for(uint64_t index = 0; index < t; index ++)
    {
        cin >> n[index];
        cin >> m[index];

        cin >> ws;
        getline(cin, string_a[index]);
        cin >> ws;
        getline(cin, string_b[index]);
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        ptr_a = 0;
        ptr_b = 0;

        while(ptr_a < string_a[index].length() && ptr_b < (string_b[index].length()))
        {
            if(string_a[index][ptr_a] != string_b[index][ptr_b])
            {
                ptr_b ++;
            }

            if(string_a[index][ptr_a] == string_b[index][ptr_b])
            {
                output[index] ++;
                ptr_a ++;
                ptr_b ++;
            }

        }
        
    }

    for(uint64_t index = 0; index < t; index ++)
    {
        cout << output[index] << endl;
    }


    return 0;
}




















