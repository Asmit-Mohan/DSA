/* Time :- O(Nlogk) Space :- O(K) */

/* GeeksForGeeks */

class Solution
{
  public:
    vector<int> kthLargest(int k, int arr[], int n)
    {
        vector<int>ans;
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0; i<n; i++)
        {
            pq.push(arr[i]);
            if(pq.size() < k)
            {
                ans.push_back(-1);
            }
            else if(pq.size() == k)
            {
                ans.push_back(pq.top());
            }
            else
            {
                pq.pop();
                ans.push_back(pq.top());
            }
        }
        return ans;   
    }
};

/* Leetcode */

class KthLargest
{
public:
    
    priority_queue<int,vector<int>,greater<int>>pq;
    int track=INT_MIN;
    
    KthLargest(int k, vector<int>& nums)
    {
        track=k;
        for(int i=0; i<nums.size(); i++)
        {
            m.push(nums[i]);
            if(m.size()>k)
            {
                m.pop();
            }
        }
    }
    
    int add(int val)
    {
        m.push(val);
        if(m.size()>track)
        {
            m.pop();
        }
        return m.top();
    }
};
