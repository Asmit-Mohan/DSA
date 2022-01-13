/*Approach 1 :- Accepted but not efficient (Brute Force)*/
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
vector<int>solve(vector<int>arr,int n)
{
stack <int >s;
vector<int>v;
for(int i=n-1;i>=0;i--)
{
if(s.empty())
{
    v.push_back(-1);
}
else if(s.size()>0&&s.top()>arr[i])
{
    v.push_back(s.top());
}
else if(s.size()>0 && s.top()<=arr[i])
{
while(s.size()>0 && s.top()<=arr[i])
{
    s.pop();
}
if(s.size()==0)
{
    v.push_back(-1);
}
else
{
v.push_back(s.top());
}
}
s.push(arr[i]);
}
reverse(v.begin(),v.end());
return v;
}
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int>NGR;
        vector<int>ans;
        NGR=solve(nums2,nums2.size());
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++)
        {
            mp[nums2[i]]=NGR[i];
        }
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};
