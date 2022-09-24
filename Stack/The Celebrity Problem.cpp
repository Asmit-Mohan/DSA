/* Approach 1 :- O(N) Time and O(N) Space */  

/* For Furthur more approaches visit :- https://www.geeksforgeeks.org/the-celebrity-problem */

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

/* Approach 2 :- O(N) Time O(1) Space */

class Solution 
{
    public:
    int celebrity(vector<vector<int> >& arr, int n) 
    {
          int i = 0;
          int j = n - 1;

          while (i < j)
          {
                if (M[j][i] == 1) 
                {
                    j--;              /* That means j cannot be the candidate for celebrity */
                }
                else
                {
                    i++;            /* That means i cannot be the candidate for celebrity */
                }
          }

          int candidate = i;   /* At last i will be the celebrity but cross-check is necessary */
          for (i = 0; i < n; i++)
          {
                if (i != candidate)
                {        
                    if (M[i][candidate] == 0 || M[candidate][i] == 1)
                    {
                        return -1;
                    }
                }
          }
          return candidate;
     }
};
