/* Approach 1 :- Accepted but not efficient (Brute Force) */

class Solution
{
public:
    int solve(int idx,vector<int>v)
    {
        if(idx+1==v.size())
        {
            return -1;
        }
        else
        {
            int ans=-1;
            int search=v[idx];
            for(int i=idx+1;i<v.size();i++)
            {
                if(v[i]>search)
                {
                    ans=v[i];
                    break;
                }
            }
            return ans;
        }
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
       unordered_map<int,int>mp;
       vector<int>ans;
       for(int i=0;i<nums2.size();i++)
       {
           mp[nums2[i]]=i;
       }
       for(int i=0;i<nums1.size();i++)
       {
           int idx=mp[nums1[i]];
           ans.push_back(solve(idx,nums2));
       }
       return ans;
    }
};

/*Approach :- 2 Using Stack Efficient approach*/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        stack<int>s;
        int n=nums2.size();
        unordered_map<int,int> mp;
        
        for(int i=n-1;i>=0;i--)
        {
            while(s.size()>0 && s.top()<=nums2[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                mp[nums2[i]]=-1;
            }
            else
            {
                mp[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            nums1[i]=mp[nums1[i]];
        }
        return nums1;    
    }
};
