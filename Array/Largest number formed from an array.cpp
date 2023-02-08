class Solution
{
public:
    bool static comp(string &a,string &b)
    {
        string ab = a+b;
        string ba = b+a;
        return ab>ba;
    }

    string largestNumber(vector<int>& nums)
    {
        string ans="";
        int count=0;
        vector<string>temp;
	    
        for(auto x : nums)
        {
            if(x==0)
            {
                count++;
            }
            temp.push_back(to_string(x));
        }

        if(count==nums.size())
        {
            return "0";
        }
        sort(temp.begin(),temp.end(),comp);

        for(auto x : temp)
        {
            ans+=x;
        }
        return ans;        
    }
};
