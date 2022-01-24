/*Logic :- To keep tracking which arr[i] is longest subsequence of given string S ie. largest word when minimum number of deletion which is only possible,
  when longest subsequence is considered*/

class Solution
{
  public:
    string findLongestWord(string S, vector<string>arr)
    {
        sort(arr.begin(),arr.end());
        int n1=S.size();
        string temp="";
        
        for(int i=0;i<arr.size();i++)
        {
            int j=0;
            int k=0;
            int n2=arr[i].size();
            
            if(n1<n2)
            {
                continue;
            }
            while(j<n2 && k<n1)
            {
                if(arr[i][j]==S[k])
                {
                    j++;
                }
                k++;
            }
            if(j==n2 && temp.size()<arr[i].size())
            {
               temp=arr[i];
            }
        }
        return temp;
    }
};
