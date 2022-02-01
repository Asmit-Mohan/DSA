/* Approach 1 Brute Optimal Solution */

void sort012(int a[], int n)
{
    int one=0;
    int two=0;
    int zero=0;
    
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            zero++;
        }
        else if(a[i]==1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }
    
    for(int i=0;i<n;i++)
    {
       if(zero!=0&&one!=0&&two!=0)
       {
            a[i]=0;
            zero--;
       }
       else if(zero==0&&one!=0&&two!=0)
       {
            a[i]=1;
            one--;
       }
       else
       {
            a[i]=2;
            two--;
       }
    }
}

/* Approach 2 Efficient using The Dutch Nation Flag Problem */

class Solution
{
    public static void sort012(int a[], int n)
    {
        int low=0;
        int high=n-1;
        int mid=0;
        
        while(mid<=high)
        {
            if(a[mid] ==0)
            {
                int temp = a[mid];
                a[mid] = a[low];
                a[low] = temp;
                low++;
                mid++;
            }
            else if(a[mid] ==1)
            {
                mid++;
            }
            else if(a[mid] ==2)
            {
                int temp = a[mid];
                a[mid] = a[high];
                a[high] = temp;
                high--;
            }
        }
    }
};
