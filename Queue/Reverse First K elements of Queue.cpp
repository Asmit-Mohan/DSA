queue<int> modifyQueue(queue<int> q, int k)
{
    int n=q.size();
    vector <int> v;
    for(int i=0;i<k;i++)
    {
        v.push_back(q.front());
        q.pop();
    }
    reverse(v.begin(),v.end());
    for(int i=k;i<n;i++)
    {
        v.push_back(q.front());
        q.pop();
    }
    queue<int> q1;
    for(int i=0;i<v.size();i++)
    {
        q1.push(v[i]);
    }
    return q1;
}
