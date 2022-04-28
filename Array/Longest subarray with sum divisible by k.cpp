/* Approach 1 */
class Solution
{
public:	
    int longSubarrWthSumDivByK(int A[], int n, int k)
    {
        int sum=0;
        int ans=0;
        int j=0;
        unordered_map<int,int> mp;
        mp[0]=0;
 
        while(j<n)
        {
            sum=sum+A[j];
            sum=((sum%k)+k)%k; // as the sum can be negative so taking modulo twice.
            
            if(mp.find(sum)!=mp.end())  
            {
                ans=max(ans,j-mp[sum]+1);
            }
            if(mp.find(sum)==mp.end())
            {
                 mp[sum]=j+1;
            }
            j++;
        }
 
        return ans;   
    }
};

/* Approach 2 */

class Solution
{
public:	
    int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        unordered_map<int,int>mp;
        mp[0]=0;
        int ans=0;
        int sum=0;
        int j=0;
        
        while(j<n)
        {
            sum=sum+arr[j];
            int remain=sum%k;
            if(remain<0)
            {
                remain=remain+k;
            }
            
            if(mp.find(remain)!=mp.end())
            {
                ans=max(ans,j-mp[remain]+1);
            }
            
            if(mp.find(remain)==mp.end())
            {
                mp[remain]=j+1;
            }
            j++;
        }
        return ans;  
    }
};
