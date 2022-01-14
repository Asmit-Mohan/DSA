/*Brute Approach*/

string solve(int n)
{
    string res;
    while (n > 0)
    {
        char temp=(n%2)+'0';
        res=res+temp;
        n=n/2;
    }
    reverse(res.begin(),res.end());
    return res;
}

vector<string> generate(int N)
{
    vector<string>ans;
    for(int i=1;i<=N;i++)
    {
        string temp=solve(i);
        ans.push_back(temp);
    }
    return ans;
}

/*Queue Approach*/

vector<string> generate(int N)
{
vector<string> result;
queue<string> q;
q.push("1");
for (int i = 0; i < N; i++)
{
    result.push_back(q.front());
    q.push(q.front()+"0");
    q.push(q.front()+"1");
    q.pop();
}
return result;
}
