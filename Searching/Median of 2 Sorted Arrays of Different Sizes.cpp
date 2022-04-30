/* Approach 1 (Naive) Time :- O(Max(m,n)) Space :- O(m+n) */
class Solution
{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
       int i=0;
       int j=0;
       int m=nums1.size();
       int n=nums2.size();
       vector<int>v;
 
       while(i<m&&j<n)
       {
           if(nums1[i]>nums2[j])
           {
               v.push_back(nums2[j]);
               j++;
           }
           else
           {
               v.push_back(nums1[i]);
               i++;
           }
       }
       while(i<m)
       {
           v.push_back(nums1[i]);
           i++;
       }
       while(j<n)
       {
           v.push_back(nums2[j]);
           j++;
       }
 
        if (v.size()%2!=0)
        {
            return (double)v[v.size() / 2];
        }
        else
        {
            return (double)(v[(v.size() - 1) / 2] + v[(v.size()) / 2 ]) / 2;
        }
    }
};

/*Approach 2 Efficient (Binary Search) Time :- O(min(log n, log m)) Space:- O(1) */

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size()>nums2.size())
        {
            return findMedianSortedArrays(nums2,nums1);  /* As we want nums1 to be smaller vector each time as binary search to be applied on smaller vector*/
        }
        
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0;
        int high=n1;
        
        while(low<=high)
        {
            int cut1=low+(high-low)/2;
            int cut2=(n1+n2+1)/2-cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(left1<=right2&&left2<=right1)
            {
                if((n1+n2)%2==0)
                {
                   return (max(left1,left2)+min(right1,right2))/2.0; 
                }
                else
                {
                    return max(left1,left2);
                }
            }
            else if(left1>right2)
            {
                high=cut1-1;   
            }
            else
            {
                low=cut1+1;
            }
        }
        return 0.0;
    }
};
