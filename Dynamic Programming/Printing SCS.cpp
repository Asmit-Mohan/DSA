class Solution
{
public:
    string shortestCommonSupersequence(string X, string Y)
    {
        
    int m=X.length();
    int n=Y.length();
    int t[m + 1][n + 1];
    int i,j;
        
    for (i = 0; i <= m; i++)
    {
	for (j = 0; j <= n; j++)
	{
	     if(i == 0)
             {
		  t[0][j] = j;
	     }
	     else if(j == 0)
             {
                t[i][0] = i;
             }
	     else if(X[i - 1] == Y[j - 1])
             {
		 t[i][j] =  t[i - 1][j - 1]+1;
             }
	    else
            {
	         t[i][j] =  min(t[i-1][j],t[i][j-1])+1;
            }
        }
    }
        
    string s;
    i--;
    j--;
        
	while (i > 0 && j > 0)
	{
		if (X[i - 1] == Y[j - 1])
		{
			s.push_back(X[i - 1]);
			i--;
			j--;
		}
		else if (t[i - 1][j] > t[i][j - 1])
		{
			s.push_back(Y[j - 1]);
			j--;                
		}
		else
		{
			s.push_back(X[i - 1]);
			i--;                   
		}
	}
        while (i > 0)
	{
		s.push_back(X[i - 1]);
		i--;
	}
	while (j > 0)
	{
		s.push_back(Y[j - 1]);
		j--;
	}
	reverse(s.begin(),s.end());
	return s;
    }
};
