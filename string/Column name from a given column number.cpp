/* Time :- O(logn) Space :- O(1) */

class Solution
{
public:
    string colName (long long int n)
    {
        string result = "";
        while(n)
        {
            char c = 'A' + (n - 1) %26;
            result = c + result;
            n = (n - 1)/26;
        }
        return result;
    }
};
