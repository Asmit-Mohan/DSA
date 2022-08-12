/* Using Inbuilt Function npos */

class Solution
{
public:
    bool rotateString(string str1, string str2)
    {
         if (str1.length() != str2.length())
         {
             return false;
         }
        string temp = str1 + str1;
        return (temp.find(str2) != string::npos);
    }
};

/* Approach 2 */

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int i;
        int n = s.length();
        string temp = "";
    
        if(s.length()==0 && goal.length()==0)
        {
            return true;
        }
        
        if(s.size()!=goal.size())
        {
            return false;
        }
        
        for(i=0;i<n;i++)
        {
            temp = s.substr(i);
            temp.append(s.substr(0,i));
            if(temp==goal)
            {
                return true;
            }
        }
        return false;
    }
};
