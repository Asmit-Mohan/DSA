 void result(string S,string op,vector<string>&ans)
    {
        if(S.length()==0)
        {
            ans.push_back(op);
            return;
        }
        string op1=op;
        string op2=op;
        op1.push_back(' ');
        op1.push_back(S[0]);
        op2.push_back(S[0]);
        S.erase(S.begin() + 0);
        result(S,op1,ans);
        result(S,op2,ans);
        return;
    }
    vector<string> permutation(string S)
    {
       vector<string>ans;
       string op="";
       op.push_back(S[0]);
       S.erase(S.begin() + 0);
       result(S,op,ans);
       return ans;
    }
