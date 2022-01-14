class Solution
{
public:
vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
priority_queue<pair<int,vector<int>>> pq;
for(int i=0;i<points.size();i++)
{
  int x=points[i][0];
  int y=points[i][1];
  pq.push({(x*x)+(y*y),{x,y}});
  if(pq.size()>k)
  {
      pq.pop();
  }
}
vector<vector<int>> v;
while(pq.size())
{
   v.push_back(pq.top().second); 
   pq.pop();
}
return v;   
}
};
