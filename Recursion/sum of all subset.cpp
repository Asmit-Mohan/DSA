class Solution
{
public:
    void solve(vector<int>&nums,vector<int> &v ,int i,int sum)
    {
    if(i==nums.size())
    {
        v.push_back(sum);
        return;
    }
    solve(nums , v , i+1 , sum);
    sum=sum+nums[i];
    solve(nums , v , i+1 , sum);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> v;
        int sum=0;
        solve(arr,v,0,sum);
        return v;
    }
};
