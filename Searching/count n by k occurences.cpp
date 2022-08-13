/* Time :- O(N) Space :- O(N) */

class Solution
{
    public:
    int countOccurence(int arr[], int n, int k)
    {
       unordered_map<int,int> mp;
       int ans = 0;
       int target = n/k;
       
       for(int i = 0; i < n; i++)
       {
           mp[arr[i]]++;
       }
       for(auto it: mp)
       {
           if(it.second > target)
           {
               ans++;
           }
       }
       return ans;
    }
};
