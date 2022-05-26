class Solution
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        queue<int>in;
        queue<int>out;
        stack<int>s;
        
        for(int i=0;i<popped.size();i++)
        {
            in.push(pushed[i]);
            out.push(popped[i]);
        }
        
        while(!in.empty())
        {
            int temp=in.front();
            in.pop();
            if(temp!=out.front())
            {
                s.push(temp);
            }
            else
            {
                out.pop();
                while(!s.empty())
                {
                    if(s.top()==out.front())
                    {
                        s.pop();
                        out.pop();
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return (in.empty()&&s.empty());
    }
};
