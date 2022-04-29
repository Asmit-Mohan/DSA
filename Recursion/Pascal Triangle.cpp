class Solution
{
public:
    
    /* Approach 1 */
    
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
    
     /* Approach 2 */
    
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
