/* Time :- O(N) Space :- O(N) */

class Solution
{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        unordered_map<int,int>mp;
        vector<int>ans;
        int i=0;
        int j=0;
        
        while(j<n)
        {
           mp[arr[j]]++;
           if(j-i+1==k)
           {
               ans.push_back(mp.size());
               if(mp[arr[i]]==1)
               {
                   mp.erase(arr[i]);
               }
               else
               {
                   mp[arr[i]]--;
               }
               i++;
               j++;
           }
           else
           {
               j++;
           }
        }
        return ans;
    }
};
