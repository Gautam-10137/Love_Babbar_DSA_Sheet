#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> getMinMax(vector<int> arr)
    {
        int maxe = INT_MIN;
        int mine = INT_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            maxe = max(maxe, arr[i]);
            mine = min(mine, arr[i]);
        }
        //  return {mine,maxe};
        return make_pair(mine, maxe);
    }
};