class Solution
{
	public:
	vector<int> findMaxGuests(int start[], int end[], int n)
	{
        sort(start,start+n);
        sort(end,end+n);
        
        int curr_guest=1;
        int max_guest=1;
        int req_time = start[0];
        int i=1;
        int j=0;
        
        while(i<n&&j<n)
        {
            if(start[i]<=end[j])
            {
                curr_guest++;
                if(curr_guest>max_guest)
                {
                    max_guest=curr_guest;
                    req_time=start[i];
                }
                i++;
            }
            else
            {
                curr_guest--;
                j++;
            }
        }
        vector<int>ans;
        ans.push_back(max_guest);
        ans.push_back(req_time);
        return ans;
	}
};
