void solve(vector<string>&ans,string in,string op,vector<bool>&flag)
    {
        if(op.length() == in.length())
        {
            ans.push_back(op);
            return;
        }
        for(int i = 0; i < in.length(); i++)
        {
            if(flag[i] == false)
            {
                flag[i] = true;
                op.push_back(in[i]);
                solve(ans, in, op, flag);
                flag[i] = false;
                op.pop_back();
            }
        }
   }
    vector<string>permutation(string S)
    {
        vector<string>ans;
        string temp;
        vector<bool> flag(S.length(), false);
        solve(ans, S, temp, flag);
        sort(ans.begin(),ans.end());
        return ans;
    }
