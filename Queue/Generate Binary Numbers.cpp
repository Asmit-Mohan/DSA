/* Brute Approach Time :- O(Nlogn) Space :- O(N) */

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

/*Queue Approach Time :- O(N) Space :- O(N) */

vector<string> generate(int N)
{
    queue<string>q;
    vector<string>ans;
    q.push("1");
    
    while(ans.size()!=N)
    {
        string front=q.front();
        ans.push_back(front);
        q.pop();
        q.push(front+"0");
        q.push(front+"1");
    }
    return ans;
}
