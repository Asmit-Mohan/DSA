class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
       int ans=0;
       int minVal=prices[0];
       for(int i=1;i<prices.size();i++)
       {
           if(minVal>prices[i])
           {
               minVal=prices[i];
           }
           int temp=prices[i]-minVal;
           if(temp>ans)
           {
               ans=temp;
           }
       }
        return ans;
    }
};