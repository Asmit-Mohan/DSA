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
