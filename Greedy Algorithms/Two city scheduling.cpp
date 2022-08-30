/* Time :- O(Nlogn) Space :- O(1) */

class Solution
{
public:
    static bool comp(vector<int>&v1,vector<int>&v2)
    {
        return (v1[1]-v1[0])>(v2[1]-v2[0]);    
    }
    
    int twoCitySchedCost(vector<vector<int>>& cost)
    {
        int ans=0;
        sort(cost.begin(),cost.end(),comp);
        
        for(int i=0;i<cost.size();i++)
        {
            if(i<cost.size()/2)
            {
                ans = ans + cost[i][0];
            }
            else
            {
                ans = ans + cost[i][1];
            }
        }
        return ans;
    }
};
