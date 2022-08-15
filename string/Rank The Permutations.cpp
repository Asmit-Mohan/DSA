/* Time :- O(N*N) Space :- O(N) */

/* Approach 1 Using Inbuilt Function */

class Solution
{
public:
    int rank(string S)
    {
        unordered_set<char>s;
        int mod=1000003;
        
        for(int i=0;i<S.length();i++)
        {
            s.insert(S[i]);
        }
        
        if(s.size()!=S.length())
        {
            return 0;    
        }
        
        int ans=1;
        
        string k=S;
        sort(k.begin(),k.end());
        
        while(k!=S)
        {
            next_permutation(k.begin(),k.end());
            ans++;
        }
        return ans%mod;
    }
};

/* Approach 2 Making our own nextPermutation Function */

class Solution
{
public:
    string nextPermutation(string nums)
    {
        int n = nums.size();
        int k;
        int l;
    	
    	for (k = n - 2; k >= 0; k--)
    	{
            if (nums[k] < nums[k + 1])
            {
                break;
            }
        }
        
    	if (k < 0)
    	{
    	    reverse(nums.begin(), nums.end());
    	}
    	else
    	{
    	    for (l = n - 1; l > k; l--)
    	    {
                if (nums[l] > nums[k])
                {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
        return nums;
    }
    
    int rank(string S)
    {
        unordered_set<char>s;
        int mod=1000003;
        
        for(int i=0;i<S.length();i++)
        {
            s.insert(S[i]);
        }
        
        if(s.size()!=S.length())
        {
            return 0;    
        }
        
        int ans=1;
        
        string k=S;
        sort(k.begin(),k.end());
        
        while(k!=S)
        {
            k=nextPermutation(k);
            ans++;
        }
        return ans%mod;
    }
};
