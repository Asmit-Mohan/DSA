class Solution
{
public:
    int count=0;
    void backtrack(string &in,string &op,int k,string &temp,vector<bool>& visited)
    {
        if(temp.size()==in.length())
        {
            count++;
            if( count==k)  
            {
            	op = temp;  
            }
            return;
        }
        
        for(int i=0;i<in.length();i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                temp.push_back(in[i]);  
                backtrack(in,op,k,temp,visited);
                temp.pop_back();  
                visited[i]=false;
            }
        }
    }
    string getPermutation(int n, int k)
    {
        string s;
        string temp;
        string ans;
        for(int i=1;i<=n;i++)
        {
            s.push_back(i+'0');
        }
        vector<bool> visited(n,false);
        backtrack(s,ans,k,temp,visited);
        return ans;
    }
};
