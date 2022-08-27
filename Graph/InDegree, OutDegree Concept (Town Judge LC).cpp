class Solution
{
public:
    int findJudge(int n, vector<vector<int>>& edges)
    {
        if(n==1)
        {
            return 1;
        }
        vector<int>hashInDegree(n+1,0);
        vector<int>hashOutDegree(n+1,0); 
        
        for(int i=0;i<edges.size();i++)
        {
           hashOutDegree[edges[i][0]]++;
           hashInDegree[edges[i][1]]++;
        }
       
        for(int i=0;i<n+1;i++)
        {
            if(hashOutDegree[i]==0&&hashInDegree[i]==n-1)
            {
                return i;
            }
        }
        return -1;
    }
};
