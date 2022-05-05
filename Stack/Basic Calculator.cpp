class Solution 
{
    public:
    int calculate(string s) 
    {        
        stack<int> st;    
        int result = 0;
        int sign = 1;
        
        for(int i = 0; i < s.length(); i++) 
        {
            if(s[i] == ' ')
            {
                continue;
            }
            
            if(isdigit(s[i])) 
            {
                int val = 0;    
                while(i < s.length() && isdigit(s[i])) 
                {
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                result+= (val * sign);
                i--;
            }
            
            else if(s[i] == '+')
            {
                sign = 1;
            }
            else if(s[i] == '-')
            {
                sign = -1;
            }
            else if(s[i] == '(') 
            {    
                st.push(result);
                st.push(sign);   
                result = 0;
                sign = 1;
            }
            else 
            {    
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }
        return result;
    }
};
