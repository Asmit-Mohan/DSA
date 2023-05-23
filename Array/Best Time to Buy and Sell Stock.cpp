class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int minimum=INT_MAX;
        int ans=INT_MIN;

        for(int i=0;i<prices.size();i++)
        {
            minimum=min(minimum,prices[i]);
            ans=max(ans,prices[i]-minimum);
        }
        return ans;    
    }
};
