/*A1:- O(N) space and O(N) Time*/

class Solution 
{
    public:
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            s.push(i);          
        }
        while(s.size()>=2)
        {
            int i=s.top();
            s.pop();
            int j=s.top();
            s.pop();
            if(arr[i][j]==1)
            {
                s.push(j);
            }
            else
            {
                s.push(i);
            }
        }
        int ans=s.top();
        for(int i=0;i<n;i++)
        {
            if(i!=ans)
            {
                if(arr[ans][i]==1||arr[i][ans]==0)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};

/*A2:- O(N) Time and constant space*/
class Solution 
{
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
      int can;
      for(int i=0;i<n;i++)
      {
          if(M[can][i]==1)
          {
              can=i;
          }
      }
      for(int i=0;i<n;i++)
      {
          if(can!=i and (M[can][i]==1 or M[i][can]==0))
          {
              return -1;
          }
      }
      return can;
    }
};
