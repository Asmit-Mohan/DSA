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
