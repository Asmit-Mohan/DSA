/* Approach 1 Brute Force Generate all string */

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

/* Approach 2 Optimal */

class Solution
{
public:
    void solve(int n, int &k, string temp, char prev, string &ans)
    {
        if(n==0)
        {
            k--;
            ans = temp;
            return;
        }

        if(prev != 'a')
        {
            solve(n - 1, k, temp + 'a', 'a', ans);
        }

        if(k && prev != 'b')
        {
            solve(n - 1, k, temp + 'b', 'b', ans);
        }

        if(k && prev != 'c')
        {
            solve(n - 1, k, temp + 'c', 'c', ans);       
        }
    }

    string getHappyString(int n, int k)
    {

        string ans;
        solve(n, k, "", '\0', ans);
        if(k>0)
        {
            return "";
        }
        else
        {
            return ans;
        }
    }
};
