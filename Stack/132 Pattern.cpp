class Solution
{
public:
bool find132pattern(vector<int>& nums)
{
int n=nums.size();
int i,j;
vector<int>v(n);
v[0]=nums[0];
stack<int>st;
for(i=1;i<n;i++)
{
   v[i]=min(v[i-1],nums[i]);
}
    for(j=n-1;j>=0;j--)
    {
        if(nums[j]>v[j])
        {
            while(st.size()>0 and v[j]>=st.top())
            {
                st.pop();
            }
            if(st.size()>0 and st.top()<nums[j])
            {
                return true;
            }
            st.push(nums[j]);
        }
    }
      return false;
}
};
