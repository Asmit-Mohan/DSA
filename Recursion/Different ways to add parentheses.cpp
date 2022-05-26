class Solution
{
public:
    vector<int> diffWaysToCompute(string s)
    {
        int i, j, k;
        vector<int> ans;

        for(i = 0; i < s.size( ); i++)
        {    
            char ch = s[i];

            if(ch == '+' || ch == '-' || ch == '*')
            {          
                string ls = s.substr(0,i);
                string rs = s.substr(i+1);

                vector<int> left = diffWaysToCompute(ls);
                vector<int> right = diffWaysToCompute(rs);

                for(j = 0; j < left.size(); j++)
                {    
                    for(k = 0; k < right.size( ); k++)
                    {
                        if(ch == '+')
                        {    
                            ans.push_back(left[j]+right[k]);
                        }
                        if(ch == '-')
                        {
                            ans.push_back(left[j]-right[k]);
                        }
                        if(ch == '*')
                        {    
                            ans.push_back(left[j]*right[k]);
                        }
                    }
                }
            }
        }
        if(ans.size( ) == 0)
        {   
            ans.push_back(stoi(s));
        }
        return ans;
    }
};
