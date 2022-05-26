class Solution
{
public:
    
    static int comp(string a,string b)
    {
        string ab=a.append(b);
        string ba=b.append(a);
        return ab.compare(ba)>0?1:0;
    }
    
	string printLargest(vector<string> &arr)
	{
	    int count=0;
	    string ans="";
	    vector<string>temp;
	    
	    for(int i=0;i<arr.size();i++)
	    {
	        if(arr[i]=="0")
	        {
	            count++;
	        }
	        temp.push_back(arr[i]);
	    }
	    
	    sort(temp.begin(),temp.end(),comp);
	    if(count==arr.size())
	    {
	        while(count--)
	        {
	            ans+=to_string(0);
	        }
	    }
	    else
	    {
	        for(int i=0;i<temp.size();i++)
	        {
	           ans+=temp[i];
	        }
	    }
	    return ans;
	}
};
