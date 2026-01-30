#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main(void)
{
    uint64_t n;
    uint64_t k;
    vector<uint64_t> arr;
    int64_t left = 0;
    int64_t right = 0;
    int64_t mid = 0;
    uint64_t output = 0;

    cin >> n;
    cin >> k;
    arr.resize(n + 1);

    arr[0] = k;
    for(uint64_t index = 1; index <= n; index ++)
    {
        arr[index] = arr[index - 1] + 5*index;
    }

    left = 1;
    right = n;
    mid = (left + right) / 2;
    while(left <= right)
    {
        // cout << "arr[mid] = " << arr[mid] << endl;
        if(arr[mid] < 240)
        {
            // cout << "DEBUG_1" << endl;
            left = mid + 1;
            mid = (left + right) / 2;
        }
        else if(arr[mid] == 240)
        {
            // cout << "DEBUG_2" << endl;
            output = mid;
            break;
        }
        else if(arr[mid] > 240)
        {
            // cout << "DEBUG_3" << endl;
            if(arr[mid] - 5*mid < 240)
            {
                // cout << "DEBUG_4" << endl;
                output = mid - 1;
                break;
            }
            else
            {
                right = mid - 1;
                mid = (left + right) / 2;
            }
        }
    }

    if(left > right || right < left)
    {
        output = mid;
    }

    cout << output << endl;


    return 0;
}




