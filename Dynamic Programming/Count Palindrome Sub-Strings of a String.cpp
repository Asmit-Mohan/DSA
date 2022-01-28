/*Brute Force Time :- O(N^3) Space :- O(1) */

bool ispalin(char arr[],int i,int j)
{
    int flag=1;
    while(i<j)
    {
        if(arr[i]!=arr[j])
        {
            flag=0;
            break;
        }
        i++;
        j--;
    }
    return flag;
}

int CountPS(char arr[], int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            count=count+ispalin(arr,i,j);
        }
    }
    return count;
}

/*DP Approach Time :- O(N^2) Space :- O(N^2) */

#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

bool isPal(string s, int i, int j)
{
      if (i > j)
      {
        return 1;
      }
      if (dp[i][j] != -1)
      {
        return dp[i][j];
      }
      if (s[i] != s[j])
      {
         return dp[i][j] = 0;
      }
      return dp[i][j] = isPal(s, i + 1, j - 1);
}

int countSubstrings(string s)
{
    memset(dp, -1, sizeof(dp));
    int n = s.length();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isPal(s, i, j))
            {
              count++;
            }
        }
    }
    return count;
}

int main()
{
    string s = "geek";
    cout << countSubstrings(s);
    return 0;
}
