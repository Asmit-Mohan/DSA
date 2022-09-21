/* Total 4 Approaches are mentioned below */

/* Approach 1 --> Time O(N) Space O(N) */

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
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
		map<int,int,greater<int>>mp;
        int i=0;
        int j=0;
        vector<int>ans;
        
        while(j<nums.size())
        {
            mp[nums[j]]++;
            if(j-i+1==k)
            {
                int temp = mp.begin()->first;
                ans.push_back(temp);
                if(mp[nums[i]]==1)
                {
                    mp.erase(nums[i]);
                }
                else
                {
                    mp[nums[i]]--;
                }
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return ans;
	}
};

/* Approach 3 Time :- O(Nlogk) Space :- O(K) */

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
	vector<int> ans;
	priority_queue<pair<int,int>> pq;
        int j=0;
        
        while(j<k)
        {
            pq.push({nums[j],j});
            j++;
        }
        
	ans.push_back(pq.top().first);
	while(j<nums.size())
        {
	      pq.push({nums[j],j});
	      while(!pq.empty() && pq.top().second < j-k+1)
              {
                  pq.pop();
              }
	     ans.push_back(pq.top().first);
             j++;
	}
	return ans;
    }
};

/* Approach 4 */

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
