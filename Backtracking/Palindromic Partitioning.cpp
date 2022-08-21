/* Time Complexity :- O( (2^n) *k*(n/2) )

   Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome.
   O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

   Space Complexity: O(k * x) --> 
   
   Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer.
   The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n) */
    

class Solution
{
public:
    bool isPalindrome(string str, int l, int r)
    {
       while(l<=r)
       {
            if(str[l] != str[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    void solve(int index, string s, vector<string> &temp, vector<vector<string>> &ans)
    {
        if(index == s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < s.size(); ++i)
        {
            if(isPalindrome(s, index, i))
            {
                temp.push_back(s.substr(index, i - index + 1));
                solve(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, temp, ans);
        return ans;
    }
};
