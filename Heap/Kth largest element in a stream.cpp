/* Time :- O(Nlogk) Space :- O(K) */

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
