class Solution
{
public:
vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
priority_queue<int,vector<int>,greater<int>>pq;
vector<int>v;
for(int i=0;i<k;i++)
{
     for(int j=0;j<k;j++)
     {
           pq.push(arr[i][j]);
           if(pq.size()>k)
           {
              v.push_back(pq.top());
              pq.pop();
           }
     }
}
for(int i=0;i<k;i++)
{
    v.push_back(pq.top());
    pq.pop();
}
return v;
}
};
