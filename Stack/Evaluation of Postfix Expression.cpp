/* Leetcode Version */

class Solution
{
public:

bool is_digits(string &str)
{
    int start = (str[0] == '-' && str.length()>1) ? 1 : 0;
    for (int i = start;i<str.length();i++)
    {
        char ch  = str[i];
        if (!(ch >= 48 && ch <= 57))
        {
            return 0;
        }
    }
    return 1;
}
    char assignOperator(string &s)
    {
        char op;
        if(s=="/")
        {
            op='/';
        }
        else if(s=="*")
        {
            op='*';
        }
        else if(s=="+")
        {
            op='+';
        }
        else
        {
            op='-';
        }
        return op;
    }
    int evaluatePostfix(vector<string>&S)
    {
        stack<int>s;
        char op;
        
        for(int i=0;i<S.size();i++)
        {
            if(is_digits(S[i]))
            {
                s.push(stoi(S[i]));
            }
            else
            {
                op = assignOperator(S[i]);
                int val1=s.top();
                s.pop();
                int val2=s.top();
                s.pop();
                
                switch(op)
                {
                    case '+':
                    s.push(val2+val1);
                    break;
                    
                    case '-':
                    s.push(val2-val1);
                    break;
                    
                    case '*':
                    s.push(val2*val1);
                    break;
                    
                    case '/':
                    if (val1 != 0)
                    {
                        s.push(val2 / val1);
                    }
                    else
                    {
                        return 0;  
                    }
                    break;
                }
            }
        }
        return s.top();
    }
    int evalRPN(vector<string>& tokens)
    {
        return evaluatePostfix(tokens); 
    }
};
/* GFG Version Time :- O(N) Space :- O(N) */

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
