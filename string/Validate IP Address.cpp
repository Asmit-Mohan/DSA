class Solution
{
    public:
    int isValid(string s)
    {
        s.push_back('.');
        int n = s.length();
        int len = 0;
        int idx = 0;
        int countDot = 0;
        int count_num = 0;
            
        for(int i = 0; i < n; i++)
        {
            if((s[i] >= 'a' and s[i] <= 'z') || (s[i]>='A' and s[i]<='Z'))
            {
                return 0;
            }
            
            else if(s[i] != '.')
            {
                len++;
                if(len>3)
                {
                    return 0;
                }
            }
            
            else if(s[i] == '.')
            {
                countDot++;
                string temp = s.substr(idx,len);
                if(len != 0)
                {
                    int num = stoi(temp);
                    count_num++;
                    string num_count = to_string(num);
                    if(num < 0 || num > 255)
                    {
                        return 0;
                    }
                    if(temp.size() != num_count.size())
                    {
                        return 0;
                    }
                }
                len = 0;
                idx = i + 1;
            }
        }
        
        if( (countDot) != 4 || count_num != 4)
        {
            return 0;
        }
        return 1;
    }
};
