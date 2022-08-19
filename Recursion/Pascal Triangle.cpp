/* Approach 1 Time :- O(More than N*N) Space :- O(N*N) */

class Solution
{
public:
    int binomial(int n,int i)
    {
        if(i==0||i==n)
        {
            return 1;
        }
        if(i>n-i)
        {
            i=n-i;
        }
        int ans=1;
        for(int j=0;j<i;j++)
        {
            ans=ans*(n-j);
            ans=ans/(j+1);
        }
        return ans;
    }
    vector<int>getRow(int n)
    {
        vector<int>v;
        for(int i=0;i<=n;i++)
        {
            int res=binomial(n,i);
            v.push_back(res);
        }
        return v;
    }
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(getRow(i));
        }
        return v;
    }
};
     
/* Approach 2 Time :- O(More than N*N) Space :- O(N*N) */

class Solution
{
public:    
     int binomial(int n,int r)
     {
       long long int up=1;
       long long int down=1;
        
       if(r==0||r==n)
       {
           return 1;
       }
       if(r==1||r==n-1)
       {
           return n;
       }
       r=min(r,n-r);
       
       for(int i=1;i<=r;i++)
       {
           up=up*(n-r+i);
           down=down*i;
       }
       return up/down; 
    }
    
   vector<int>getRow(int n)
   {
        vector<int>v;
        for(int i=0;i<=n;i++)
        {
            int res=binomial(n,i);
            v.push_back(res);
        }
        return v;
   }
   vector<vector<int>> generate(int n)
   {
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(getRow(i));
        }
        return v;
   }
};

/* Approach 3 Time :- O(N*N) Space :- O(N*N) */

class Solution
{
public:
    vector<vector<int>> generate(int numRows) 
    {
       vector<vector<int>> ans;       
       for(int i=0;i<numRows;i++)
       {
           vector<int> temp(i+1,1);
           for(int j=1;j<i;j++)
           {
              temp[j] = ans[i-1][j-1] + ans[i-1][j];  
           }
           ans.push_back(temp);
       }
       return ans; 
    }
};
