/* Brute Force Approach Time :- O(N*N!) Space :- (N) */

class Solution
{
public:
    int count=0;
    void solve(string &in,string &op,int k,string &temp,vector<bool>& visited)
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
                solve(in,op,k,temp,visited);
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
        solve(s,ans,k,temp,visited);
        return ans;
    }
};

/* Optimal Solution Mathematics Factorial Based Approach Time :- O(N*N) Space :- O(N) */

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1; 
        vector<int> numbers; 
        for(int i = 1;i<n;i++)
        {
            fact = fact * i; 
            numbers.push_back(i); 
        }
        
        numbers.push_back(n); 
        string ans = ""; 
        k = k - 1; 
        
        while(true)
        {
            ans = ans + to_string(numbers[k / fact]); 
            numbers.erase(numbers.begin() + k / fact); 
            if(numbers.size() == 0)
            {
                break; 
            }
            k = k % fact; 
            fact = fact / numbers.size();
        }
        return ans; 
    }
};
