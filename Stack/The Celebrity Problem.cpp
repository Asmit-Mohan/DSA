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
        int can=0;
        for (int i=1;i<n;i++)
        {
            if (arr[can][i]==1)
            {
                arr[can][can]=1;
                can=i;
            }
            else
            {
                arr[i][i]=1;
            }
        }
        
        for (int i=0;i<n;i++)
        {
            if (arr[i][i]==0)
            {
                int flag=0;
                for (int j=0;j<n;j++)
                {
                    if (j!=i && arr[j][i]==0)
                    {
                        flag=1;
                        break;
                    }
                }
                if (flag==0)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};
