/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    int maxArea(vector<int>& arr)
    {
        int l=0;
        int r=arr.size()-1;
        int area=0;
        
        while(l<r)
        {
            if(arr[l]<=arr[r])
            {
                area=max(area,(r-l)*arr[l]);
                l++;
            }
            else
            {
                area=max(area,(r-l)*arr[r]);
                r--;
            }
        }
        return area;
    }
};
