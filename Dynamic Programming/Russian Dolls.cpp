/* Time :- O(Nlogn) and Space :- O(N) */

class Solution
{
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[0]==b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    
    public:
    int maxEnvelopes(vector<vector<int>>& arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end(), cmp);
        vector<int> lis;
        
        for(int i = 0;i<arr.size();i++)
        {   
            int idx = lower_bound(lis.begin(), lis.end(), arr[i][1]) - lis.begin();
            if(idx >= lis.size())
            {
                lis.push_back(arr[i][1]);
            }
            else
            {
                lis[idx] = arr[i][1];
            }
        }
        return lis.size();
    }
};
