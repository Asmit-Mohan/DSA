/* Approach 1 :-  Time :- O(N)  Space :- O(N) */

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        if(n==1)
        {
            return 1;
        }
        else
        {
            return (findTheWinner(n-1,k)+k-1)%n+1;
        }
    }
};

/* Approach 2 :- Time :- O(N*K) Space :- O(N) */

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int>q;
        for(int i=1;i<=n;i++)
        {
            q.push(i);
        }
        
        int i=0;
        while(q.size()!=1)
        {
            i++;
            int temp=q.front();
            if(i==k)
            {
                q.pop();
                i=0;
            }
            else
            {
                q.pop();
                q.push(temp);
            }
        
        }
        return q.front();
    }
};

/* Approach 3 :-  Time :- O(N*N)  Space :- O(N) */

class Solution
{
public:
    int ans;
    void solve(int index,int k,int n,vector<int>v)
    {
        if(v.size()==1)   /* Last value will be postion of Josephus*/
        {
            ans=v[0];
            return;
        }
        index=(index+k)%v.size();   /* In case circular ie, last index move to starting postion */
        v.erase(v.begin()+index);   
        solve(index,k,n,v);
    }
    
    int findTheWinner(int n, int k)
    {
        int index=0;
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            v.push_back(i);
        }
        k--;                 /* Because indexing starts from current person */
        solve(index,k,n,v);
        return ans;
    }
};
