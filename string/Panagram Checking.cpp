/* Time :- O(N) Space :- O(1) */

class Solution
{
  public:
    bool checkPangram (string &str)
    {
        unordered_set<char>s;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
            {
                s.insert(str[i]);
            }
        }
        return s.size()==26?1:0;
    }
};
