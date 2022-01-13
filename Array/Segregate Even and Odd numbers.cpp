class Solution
{
public:	
	void segregateEvenOdd(int arr[], int n)
	{
	     vector<int>even;
	     vector<int>odd;
         for(int i=0;i<n;i++)
         {
             if(arr[i]%2==0)
             {
                 even.push_back(arr[i]);
             }
             else
             {
                 odd.push_back(arr[i]);
             }
         }
         sort(even.begin(),even.end());
         sort(odd.begin(),odd.end());
         int j=0;
         for(int i=0;i<even.size();i++)
         {
             arr[i]=even[i];
             j=i;
         }
         j++;
         for(int i=0;i<odd.size();i++)
         {
             arr[j]=odd[i];
             j++;
         }
	}
};