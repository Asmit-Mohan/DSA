class Solution
{
    public:
    vector<string> all;
     void generateStrings(int n, string s)
    {
        if(n == 0)
        {
            all.push_back(s);
            return;
        }
    
        for(char i = 'a' ; i <= 'c' ; i++) 
        {
            if(s.empty() || s.back() != i) 
            {
                s.push_back(i);
                generateStrings(n-1, s);
                s.pop_back();
            }
        }
    }
    
    string getHappyString(int n, int k) 
    {
        generateStrings(n, "");
        sort(all.begin(), all.end());
        if(all.size() < k)
        {
            return "";
        }
        return all[k - 1];
    }
};
