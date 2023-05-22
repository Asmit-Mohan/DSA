/* Approach 1 */

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int n=nums.size();
        if (n < 4)
        {
            return {};
        }
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        vector<vector<int>>ans;

        for(int i=0;i<n-2;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            for(int j=i+1;j<n-1;j++)
            {
                if(j>(i+1)&&nums[j]==nums[j-1])
                {
                    continue;
                }
                int l=j+1;
                int r=n-1;   
                while(l<r)
                {
                    long long temp1 = (long long)nums[i]+nums[j];
                    long long temp2 = (long long)nums[l]+nums[r];
                    long long temp = temp1 + temp2;

                    if(temp==target)
                    {
                        s.insert({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                    }   
                    else if(temp>target)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }   
        }

        for(auto it : s)
        {
            ans.push_back(it);
        }
        return ans;    
    }
};

/* Approach 2 */

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>>ans;
        int n=nums.size();
        
        if (n < 4)
        {
            return {};
        }
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            for(int j=i+1;j<n-1;j++)
            {
                if(j>(i+1)&&nums[j]==nums[j-1])
                {
                    continue;
                }

                int low = j+1;
                int high = n-1;
                long long sum = (long long)target - (long long)nums[i] - (long long)nums[j];
                
                while(low<high)
                {
                      long long data = nums[low]+nums[high];
                      if(data==sum)
                      {
                            ans.push_back({nums[i] , nums[j] , nums[low] , nums[high]});
                            low++;
                            while (low < n && nums[low] == nums[low - 1])
                            {
                                low++;
                            }
                      }
                      else if(data>sum)
                      {
                         high--;
                      }
                      else
                      {
                         low++;
                      }
                 }
            }
        }
        return ans;
    }
};
