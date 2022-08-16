/* Time :- O(N) Space :- O(N) */

class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        vector<int> right;
        vector<int> left;
        stack<pair<int, int>> l,r;
        
        for(int i=0;i<heights.size();i++)  /*NSL*/
        {
            if(l.size()==0)
            {
                left.push_back(-1);
            }
            else if(l.size()>0 && l.top().first<heights[i])
            {
                left.push_back(l.top().second);
            }
            else if(l.size()>0 && l.top().first>=heights[i])
            {
                while(l.size()>0 && l.top().first>=heights[i])
                {
                    l.pop();
                }
                if(l.size()==0)
                {
                    left.push_back(-1);
                }
                else
                {
                    left.push_back(l.top().second);
                }
            }
            l.push({heights[i], i});
        }
        for(int i=heights.size()-1;i>=0;i--)   /*NSR*/
        {
            if(r.size()==0)
            {
                right.push_back(heights.size());
            }
            else if(r.size()>0 && r.top().first<heights[i])
            {
                right.push_back(r.top().second);
            }
            else if(r.size()>0 && r.top().first>=heights[i])
            {
                while(r.size()>0 && r.top().first>=heights[i])
                {
                    r.pop();
                }
                if(r.size()==0)
                {
                    right.push_back(heights.size());
                }
                else
                {
                    right.push_back(r.top().second);
                }
            }
            r.push({heights[i], i});
        }
        reverse(right.begin(), right.end());
        int maxi=0;
        for(int i=0;i<heights.size();i++)
        {
            right[i]= right[i]-left[i]-1;
            right[i]=right[i]*heights[i];
            maxi= max(maxi, right[i]); 
        }
        return maxi;
    }
};
