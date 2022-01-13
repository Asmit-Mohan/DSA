class Solution
{
public:
	string removeDuplicates(string str)
	{
	    int array[256]={0};  //Hash Array
	    string s1="";
	    for(int i=0; i<str.size(); i++)
	    {
	        if(array[str[i]]==0)  //Means that charecter have not came earlier
	        {
	            array[str[i]]++;  //increament count
	            s1+=str[i];      //add to string since it is first unique charecter
	        }
	    }
	    return s1;
	}
}