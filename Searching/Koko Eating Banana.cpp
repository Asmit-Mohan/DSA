/* Time :- O(Nlogn) Space :- O(1) */

class Solution
{
public:
   bool solve(int mid, int hour, vector<int> &arr)
   {
        long long int count=0;
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
        return hour>=count?1:0;
  }
    
    int minEatingSpeed(vector<int>& arr, int hour)
    {
        int low = 1;
        int high = *max_element(arr.begin(),arr.end());
        int ans = -1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(solve(mid,hour,arr))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
