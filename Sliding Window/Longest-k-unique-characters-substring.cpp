/* Time :- O(N) Space :- O(K) */

class Solution
{
  public:
    int longestKSubstr(string arr, int k)
    {
        int i=0;
        int j=0;
        int ans=INT_MIN;
        unordered_map<int,int>mp;
        
        while(j<arr.length())
        {
            mp[arr[j]]++;
            
            if(mp.size()==k)
            {
                int window=j-i+1;
                ans=max(ans,window);
            }
            
            if(mp.size()>k)
            {
                while(mp.size()>k)
                {
                    mp[arr[i]]--;
                    if(mp[arr[i]]==0)
                    {
                        mp.erase(arr[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return ans==INT_MIN?-1:ans;
    }
};
