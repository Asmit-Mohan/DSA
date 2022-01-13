class Solution
{
    public:
    void clonestack(stack<int> s, stack<int>& c)
    {
        if(s.empty())
        {
            return;
        }
        else
        {
            int temp=s.top();
            s.pop();
            clonestack(s,c);
            c.push(temp);
        }
    }
};
