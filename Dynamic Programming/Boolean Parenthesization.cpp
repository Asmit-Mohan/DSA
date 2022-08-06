/* Time :- O(N*N*N) Space :- O(N*N) */

class Solution
{
public:
unordered_map<string,int>mp;
int mod=1003;

int Solve(string& X, int i, int j, bool isTrue)
{
    
if(i>j)
{
    return true;
}

if (i == j)
{
    if (isTrue==true)
    {
        return X[i] == 'T';
    }
    else
    {
        return X[i] == 'F';
    }
}

string temp=to_string(i);
temp.push_back(' ');
temp.append(to_string(j));
temp.push_back(' ');
temp.append(to_string(isTrue));

if(mp.find(temp)!=mp.end())
{
    return mp[temp];
}

int ans = 0;
for (int k = i + 1; k < j; k+=2)
{
int lT = Solve(X, i, k - 1, true);
int lF = Solve(X, i, k - 1, false);
int rT = Solve(X, k + 1, j, true);
int rF = Solve(X, k + 1, j, false);

if (X[k] == '|')
{
    if (isTrue == true)
    {
        ans += lT * rT + lT * rF + lF * rT;
    }
    else
    {
        ans += lF * rF;
    }
}
else if (X[k] == '&')
{
    if (isTrue == true)
    {
        ans += lT * rT;
    }
    else
    {
        ans += lT * rF + lF * rT + lF * rF;
    }
}
else if (X[k] == '^')
{
    if (isTrue == true)
    {
        ans += lT * rF + lF * rT;
    }
    else
    {
        ans += lT * rT + lF * rF;
    }
}
}
return mp[temp] = ans%mod;
}

int countWays(int N, string S)
{
    mp.clear();
    return Solve(S, 0, N - 1, true);
}
