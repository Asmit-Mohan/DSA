class Solution
{
  public:
    vector<int> kthLargest(int k, int nums[], int n)
    {
         priority_queue <int, vector<int>, greater<int> > minh;
         vector<int>v;
         for(int i=0;i<n;i++)
         {
             minh.push(nums[i]);
             if(minh.size()>k)
             {
                 minh.pop();
             }
             if(minh.size()<k)
             {
                v.push_back(-1);
                continue;
             }
            v.push_back(minh.top());
         }
        return v;     
    }
};
