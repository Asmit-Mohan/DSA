/* Time :- O(N*N) Space :- O(N) */

/* Approach 1 :- very least efficient */
class Solution
{
public:
vector<vector<int>> threeSum(vector<int>& nums)
{
        set<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-1; i++)
        {
            int l = i+1;
            int r = n-1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    vector<int>v{nums[i], nums[l], nums[r]};
                    ans.insert(v);
                    l++;
                    r--;
                }
                else if (nums[i] + nums[l] + nums[r] < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        vector<vector<int>>res(ans.begin(), ans.end());
        return res;
}
};

/*Approch 2:- Efficient*/
class Solution
{
public:
vector<vector<int>> threeSum(vector<int>& nums)
{
vector<vector<int>>res;
if(nums.size()<3)
{
    return res;
}
    
sort(nums.begin(),nums.end());    
for(int i=0;i<nums.size()-2;++i)
{
    int l=i+1;
    int r=nums.size()-1;
    if(i>0 and nums[i]==nums[i-1])
    {
        continue;
    }
    while(l<r)
    {
      int sum=nums[i]+nums[l]+nums[r];
      if(sum==0)
         {
             vector<int>let;
             let.push_back(nums[i]);
             let.push_back(nums[l]);
             let.push_back(nums[r]);
          
             int s=res.size();      
             res.push_back(let);
             l++;
             r--;
          
             while(l<nums.size() and nums[l-1]==nums[l])
             { 
                 l++;
             }
             while(r>0 and nums[r]==nums[r+1] )
             {
                 r--;
             }           
        }
        else if(sum>0)
        {        
           r--;
        }
        else if(sum<0)
        {            
            l++;
        }                   
    }  
}
return res;
}
};

/*Approach 3 :- Most Efficient approach*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>>v;
        if(nums.size()<3)
        {
            return v;
        }
        set<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();    
        for(int i = 0; i < n-2; i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            int start = i+1;
            int end = nums.size()-1;
            while(start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum==0)
                {
                    ans.insert({nums[i], nums[start], nums[end]});
                }
                if(sum < 0)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
    
        for(auto i : ans)
        {
            v.push_back(i);
        }
        return v;
    }
};
