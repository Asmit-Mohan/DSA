class Solution
{
public:
    int findMidSum(int nums1[], int nums2[], int n)
    {
        int n1=n;
        int n2=n;
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
                return max(left1,left2)+min(right1,right2); 
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
    }
};
