/* Time :- O(N) Space :- O(N) */ 

class Solution
{
public:
    int findMaxLength(vector<int>& nums)
    {
       int zero=0;
       int one=0;
        
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]==0)
           {
               zero++;
               nums[i]=-1;
           }
           else
           {
               one++;
           }
       }
       
       if(one==zero)
       {
          return nums.size();   
       }
        
       int i=0;
       int j=0;
       int ans=INT_MIN;
       int sum=0;
       unordered_map<int,int>mp; 
       mp[0]=0;
        
       while(j<nums.size())
       {
           sum=sum+nums[j];
           
           if(mp.find(sum)!=mp.end())
           {
               ans=max(ans,j-mp[sum]+1);
           }
           else
           {
               mp[sum]=j+1;
           }
           
           j++;
       }
       return ans==INT_MIN?0:ans;
    }
};
