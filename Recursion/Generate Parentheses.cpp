/* 
   Time complexity :- O((2^2N)*N) almost -> [2^2N] :- 
   
   (a) O(2^2N) :- for all possible paranthesis.
   (b) O(N) :- Put generated output into the res vector.
   
   Space complexity :- O((2^2N)*N) to store 2^2N comb of size N , where 2^N is (N+N)^N = ( close + open)^N 
   
*/

class Solution
{
public:
    void solve(int open,int close,string op,vector<string>&res)
    {
        if(open==0&&close==0)
        {
            res.push_back(op);
            return;
        }
        if(open>0)
        {
            string op1=op;
            op1.push_back('(');
            solve(open-1,close,op1,res);
        }
        if(close>open)
        {
            string op2=op;
            op2.push_back(')');
            solve(open,close-1,op2,res);
        }
        return;
        
    }
    vector<string> generateParenthesis(int n)
    {
         vector<string>res;
         string op;
         int open=n;
         int close=n;
         solve(open,close,op,res);
         return res;
    }
};
