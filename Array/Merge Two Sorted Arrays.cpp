/* Naive Approach Merge Function */
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
          vector<int>v;
          int i=0;
          int j=0;
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
          for(int i=0;i<(m+n);i++)
          {
              nums1[i]=v[i];
          }
    }
};

/* Efficient Approach */

class Solution
{
public:
    void merge(long long arr1[], long long arr2[], int n, int m) 
    { 
        int i=n-1;
        int j=0;
        
        while(i>=0&&j<m)
        {
            if(arr1[i]>arr2[j])
            {
                swap(arr1[i],arr2[j]);
                i--;
                j++;
            }
            else
            {
                break;
            }
        }
        
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
    } 
};
