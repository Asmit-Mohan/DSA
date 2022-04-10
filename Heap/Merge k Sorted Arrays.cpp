/* Naive Approach */

class Solution
{
public:
vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
     priority_queue<int,vector<int>,greater<int>>pq;
     for(int i=0;i<k;i++)
     {
          for(int j=0;j<k;j++)
          {
            pq.push(arr[i][j]);
          }
     }
      vector <int> v;
      while(pq.empty()==0)
      {
          v.push_back(pq.top());
          pq.pop();
      }
      return v;
}
};

/* Efficient Approach */

