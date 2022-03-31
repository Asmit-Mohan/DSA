/* Approach 1 Binary Search */

#define ll long long

class Solution
{
public:
    vector<int> distributeCandies(int n, int k)  /* N :- Candies and k :- Person */
    {
    vector<int>ans; 
    int arr[k];
    
    memset(arr, 0, sizeof(arr));
 
    ll low = 0;
    ll high = n;
    ll count = 0;
    
    while (low <= high)
    {
        ll mid = (low + high) /2;
        ll sum = (mid * (mid + 1)) /2;
       
        if (sum <= n)
        {
            count = mid / k;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    ll last = (count * k);
    n = n - (last * (last + 1)) / 2;
    ll i = 0;
    ll term = (count * k) + 1;
    
    while (n)
    {
        if (term <= n)
        {
            arr[i++] = term;
            n = n-term;
            term++;
        }
        
        else
        {
            arr[i] += n;
            n = 0;
        }
    }
        for (ll i = 0; i < k; i++)
        {
            arr[i] += (count * (i + 1)) + (k * (count * (count - 1)) / 2);
        }
        
        for (ll i = 0; i < k; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

/* Approach 2 */

class Solution
{
public:
    vector<int> distributeCandies(int candies, int person)
    {
       int j=0;
       vector<int>ans(person,0);
       while(candies>0)
       {
           for(int i=0;i<person;i++)
           {
               j++;
               candies=candies-j;
               if(candies<=0)
               {
                   ans[i]=ans[i]+candies+j;
                   break;
               }
               else
               {
                   ans[i]=ans[i]+j;
               }
           }
       }
       return ans;
     }
};
