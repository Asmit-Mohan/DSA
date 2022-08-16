/* Time :- O(N*N) [O(N) For Deleting all elements then for inserting in cloned in O(N) time]  Space :- O(1) */

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
