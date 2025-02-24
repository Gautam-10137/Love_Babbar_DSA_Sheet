#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &arr)
    {
        int n = arr.size();
        int xr = 0;
        // finding xor of that two elements;
        for (int i = 0; i < n; i++)
            xr = xr ^ arr[i];
        // finding first different bit
        int diff = (xr & ~(xr - 1));
        // will separate nums on basis of this diff bit
        int first = 0, second = 0;
        for (int i = 0; i < n; i++)
        {
            // if element has diff bit
            if (arr[i] & diff)
                first = first ^ arr[i];
            // if element donot has diff bit
            else
                second = second ^ arr[i];
        }
        // Now we have first and second element, duplicate element already removed by doing xor
        if (first > second)
        {
            int temp = second;
            second = first;
            first = temp;
        }
        return {first, second};
    }
};