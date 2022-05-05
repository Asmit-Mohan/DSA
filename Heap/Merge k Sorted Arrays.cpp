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

#define pi pair<int,pair<int,int>>;

class Solution
{
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int>v;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        
        for(int i=0;i<k;i++)
        {
            minh.push({(arr[i][0],{i,0})});
        }
        
        while(pq.size()>0)
        {
            pi x = pq.top();
            pq.pop();
            v.push_back(x.first);
            int row=x.second.first;
            int column=x.second.second;
            
            if(column<k-1)
            {
                pq.push(make_pair(arr[row][column+1], make_pair(row,column+1)));
            }
        }
        return v;
    }
};
