
class Solution
{
public:
    bool solve(vector<int>arr,int mid,int h)
    {
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            int quo=arr[i]/mid;
            int remain=arr[i]%mid;
            count=count+quo;
            if(remain!=0)
            {
                count++;
            }
        }
        return h>=count?1:0;
    }
    int minEatingSpeed(vector<int>& arr, int h)
    {
          int low=1;
          int high=INT_MAX;
          int ans=INT_MAX;
          sort(arr.begin(),arr.end());
          while(low<=high)
          {
              int mid=low+(high-low)/2;
              if(solve(arr,mid,h))
              {
                  ans=min(ans,mid);
                  high=mid-1;
              }
              else
              {
                  low=mid+1;
              }
          }
          return ans;
    }
};
