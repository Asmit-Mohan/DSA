class Solution
{
public:
    int MAH(vector<int> hist, int n)
    {
        int nsr[n],nsl[n];
        stack<pair<int,int>> s;
        for(int i=0; i<n; i++)
        {
            if(s.empty())
            {
                nsl[i]=-1;
            }
            else if(!s.empty() && s.top().first<hist[i])
            {
                nsl[i]=s.top().second;
            }
            
            else if(!s.empty() && s.top().first>=hist[i])
            {
                while(!s.empty() && s.top().first>=hist[i])
                {
                    s.pop();
                }
                
                if(s.empty())
                {
                    nsl[i]=-1;
                }
                else
                {
                    nsl[i]=s.top().second;
                }
            }
            s.push({hist[i],i});
        }
        
        while(!s.empty()) //clear stack for nsr
        {
            s.pop();
        }

        for(int i=n-1; i>=0; i--)
        {
            if(s.empty())
            {
                nsr[i]=n;
            }
            
            else if(!s.empty() && s.top().first<hist[i])
            {
                nsr[i]=s.top().second;
            }
            
            else if(!s.empty() && s.top().first>=hist[i])
            {
                while(!s.empty() && s.top().first>=hist[i])
                {
                    s.pop();
                }
                
                if(s.empty())
                {
                    nsr[i]=n;
                }
                else
                {
                    nsr[i]=s.top().second;
                }
            }
            s.push({hist[i],i});
        }
        
        int res=-1,width;
        for(int i=0; i<n; i++)
        {
            width=nsr[i]-nsl[i]-1;
            res=max(res,width*hist[i]);
        }
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int m=matrix.size();
        if(m==0)
        {
            return 0;
        }
        
        int n=matrix[0].size();
        vector<int> hist(n,0);
        int ans=-1;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]=='0')
                {
                    hist[j]=0;
                }
                else
                {
                    hist[j]+=1;
                }
            }
            ans=max(ans,MAH(hist,n));
        }
        return ans;
    }
};
