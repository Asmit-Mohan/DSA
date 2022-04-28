class Solution
{
public:
    bool canArrange(vector<int>& arr, int k)
    {
         unordered_map<int,int>mp;
        
         for(auto x : arr)
         {
             int temp = ((x%k)+k)%k;
             mp[temp]++;
         }
         
        for(auto x:arr)
        {
            int rem=(x%k + k)%k;
            if(rem==0)                         
            { 
                if(mp[rem] % 2 ==1)
                {
                    return false;
                }
            }         
            else if(mp[rem] != mp[k - rem])
            {
                return false;
            }
        }
        return true;
    }
};
