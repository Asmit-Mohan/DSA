class Solution
{
    public:
    int precedence(char p)
    {
        if(p=='^')
        {
            return 3;
        }
        else if(p=='*'||p=='/')
        {
            return 2;
        }
        else if(p=='+'||p=='-')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    string infixToPostfix(string str)
    {
        stack<char>s;
        string res;
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
            {
                res+=str[i];
            }
            else if(str[i]=='(')
            {
                s.push('(');
            }
            else if(str[i]==')')
            {
                while(!s.empty()&&s.top()!='(')
                {
                    res+=s.top();
                    s.pop();
                }
                if(!s.empty())
                {
                    s.pop();
                }
            }
            else
            {
                while(!s.empty()&&precedence(s.top())>=precedence(str[i]))
                {
                    res+=s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
        }
        while(!s.empty())
        {
            res+=s.top();
            s.pop();
        }
        return res;
    }
};
