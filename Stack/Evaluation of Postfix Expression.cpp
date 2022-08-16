/* Time :- O(N) Space :- O(N) */

class Solution
{
    public:
    int evaluatePostfix(string S)
    {
        stack<int>s;
        char op;
        
        for(int i=0;i<S.length();i++)
        {
            if(isdigit(S[i]))
            {
                s.push(S[i]-'0');
            }
            else
            {
                op=S[i];
                int val1=s.top();
                s.pop();
                int val2=s.top();
                s.pop();
                
                switch(op)
                {
                    case '+':
                    s.push(val1+val2);
                    break;
                    
                    case '-':
                    s.push(-val1+val2);
                    break;
                    
                    case '*':
                    s.push(val1*val2);
                    break;
                    
                    case '/':
                    s.push(val2/val1);
                    break;
                }
            }
        }
        return s.top();
    }
};
