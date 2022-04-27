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
	void merge(int arr1[], int arr2[], int n, int m)
	{
	    int i=0;
	    int j=0;
	    int k=n-1;
	    
	    while(i<n&&j<m)
	    {
	        if(arr1[i]>arr2[j])
	        {
	            swap(arr1[k--],arr2[j++]);
	        }
	        else
	        {
	            i++;
	        }
	    }
	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);
	}
};
