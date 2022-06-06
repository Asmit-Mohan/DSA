/*Approach 1 (Naive) Time :- O(|text|*|pat|) */

class Solution
{
    public:
    bool solve(int l,int r,string str,string pat)
    {
        int flag=1;
        int i=0;
        while(l<r)
        {
            if(pat[i]!=str[l])
            {
                flag=0;
                break;
            }
            l++;
            i++;
        }
        return flag;
    }
    
        vector <int> search(string pat, string txt)
        {
            vector<int>v;
            int n=pat.size();
            
            for(int i=0;i<=txt.size()-n;i++)
            {
                if(solve(i,i+n,txt,pat))
                {
                    v.push_back(i+1);
                }
            }
            if(v.size()==0)
            {
                v.push_back(-1);
            }
            return v;
        }
};

/* Approach 2 (Rabin Karp) Time :- O(|text|-|pat|+1) --> Average case O(|text|*|pat|) --> Worst case*/

/* Logic :- Using Rolling Hash Function to avoid spurious hit*/
/* When the hash value of the pattern matches with the hash value of a window of the text but the window is not the actual pattern then it is called a spurious hit or collision.*/
/* Mod with prime to avoid overflow, the larger the prime is, the fewer collisions it would cause.*/

class Solution
{
    public:
    void solve(string txt,string pat,int mod,int d,vector<int>&ans)
    {
        
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be pow(d,M-1)%mod
    
    for (i = 0; i < M - 1; i++)
    {
        h = (h * d) % mod;
    }
    
    /* Calculate the hash value of pattern and firstwindow of text */ 
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % mod;
        t = (d * t + txt[i]) % mod;
    }
    
       for (i = 0; i <= N - M; i++)
       {
       		/* If Hash Value Matches then there is a possibility of answer then check it */
            if ( p == t )
            {  
                bool flag = true;
                for (j = 0; j < M; j++)
                {
                    if (txt[i+j] != pat[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (j == M)
                {
                    ans.push_back(i+1);
                }
            }
            
    		/* Calculate hash value for next window of txt: Remove leading digit, add trailing digit */
            if ( i < N-M )
            {
                t = (d*(t - txt[i]*h) + txt[i+M])%mod;
                if (t < 0)  /* We might get negative value of t, converting it to positive */
                {
                    t = (t + mod);
                }
            }
       }
    }
    vector <int> search(string pat, string txt)
    {
         vector<int>ans;
         int mod=11;        /*Can be any prime number, but larger the prime minimum will be the collision*/
         int d=256;
         solve(txt,pat,mod,d,ans);
         if(ans.size()==0)
         {
             ans.push_back(-1);
         }
         return ans;
    }
};

/*Reference Links :- */

// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
// https://www.programiz.com/dsa/rabin-karp-algorithm
// https://www.youtube.com/watch?v=qQ8vS2btsxI
