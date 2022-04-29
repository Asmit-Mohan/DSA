/* Approach 1 */

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        int j=0;
        
        while(j<nums.size())
        {
            if (!dq.empty() && dq.front() == j-k) 
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[j])
            {
                dq.pop_back();  
            }
            dq.push_back(j);
            if (j>=k-1)        /* Greater than for next such window */
            {
                ans.push_back(nums[dq.front()]);
            }
            j++;
        }
        return ans;
    }
};

/* Approach 2 */

class Solution
{
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        int i=0;
        int j=0;
        vector<int>v;
        list<int>l;
        while(j<n)
        {
            while(l.size()>0&&l.back()<arr[j])
            {
                l.pop_back();
            }
            l.push_back(arr[j]);
            if(j-i+1==k)
            {
                v.push_back(l.front());
                if(l.front()==arr[i])
                {
                    l.pop_front();
                }
                i++;
                j++;
            }
            else 
            {
                j++;
            }
        }
        return v;
    }
};
