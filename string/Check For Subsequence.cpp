/* Time :- O(N) where N is length of string B && Space :- O(1) */

class Solution
{
    public:
    bool isSubSequence(string A, string B) 
    {
        int i=0;
        int j=0;
        int temp=A.length();
        int count=0;
        
        while(i<A.length()&&j<B.length())
        {
            if(A[i]==B[j])
            {
                i++;
                j++;
                count++;
            }
            else
            {
                j++;
            }
        }
        if(temp==count)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
