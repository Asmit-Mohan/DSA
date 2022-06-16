/* For GFG */

class Solution
{
  public:
    int NumberofElementsInIntersection(int a[], int b[], int n, int m)
    {
        set<int>s;
        int count=0;
        if(m>n)
        {
            for(int i=0;i<n;i++)
            {
                s.insert(a[i]);
            }
            for(int i=0;i<m;i++)
            {
                if(s.find(b[i])!=s.end())
                {
                   s.erase(b[i]);
                   count++;
                }
            }   
        }
        else
        {
            for(int i=0;i<m;i++)
            {
                s.insert(b[i]);
            }
            for(int i=0;i<n;i++)
            {
                if(s.find(a[i])!=s.end())
                {
                   s.erase(a[i]);
                   count++;
                }
            }
        }
        return count;
    }
};

/* For Leetcode 350 */

class Solution
{
        public:
	vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
	{
	   vector<int> ans;
	   unordered_map<int, int> mp;
        
        for (auto x : nums1)
        {
            mp[x]++;
        }
        
        for (auto x : nums2)
        {
            if (mp.find(x) != mp.end() && mp[x] > 0)
            {
              ans.push_back(x);
              mp[x]--;
            }
        }
       return ans; 
    }
};
