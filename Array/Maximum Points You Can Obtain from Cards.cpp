class Solution
{
public:
    int maxScore(vector <int>& arr, int k)   /* pick from both sides interviewbit */ 
    {
        int sum=0;
        
        for(int i=0;i<arr.size();i++)
        {
            sum=sum+arr[i];
        }
        
        if(k==arr.size())
        {
            return sum;
        }
        
        int window=arr.size()-k;
        int ans=INT_MAX;
        
        int i=0;
        int j=0;
        int temp=0;
        
        while(j<arr.size())
        {
            temp=temp+arr[j];   
            if(j-i+1==window)
            {
                ans=min(ans,temp);
                temp=temp-arr[i];
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return sum-ans;
    }
};
