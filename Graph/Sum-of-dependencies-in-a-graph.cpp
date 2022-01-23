class Solution
{
  public:
    int sumOfDependencies(vector<int> adj[], int n)
    {
       int sum=0;
       for(int i=0;i<n;i++)
       {
           sum=sum+adj[i].size();
       }
       return sum;
    }
};
