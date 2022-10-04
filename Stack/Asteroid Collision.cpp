/* Time :- O(N) Space :- O(N) */

class Solution
{
public:
    vector<int> asteroidCollision(vector<int>& arr)
    {
        stack<int>st;
        for(int i=0;i<arr.size();i++)
        {
            if(st.size()==0)
            {
                st.push(arr[i]);
            }
            else if(st.top()>=0&&arr[i]<=0)
            {    
                while(st.size()>0&&st.top()>0&&abs(arr[i])>st.top())
                {
                   st.pop();
                }
                if(st.size()>0&&st.top()==abs(arr[i]))
                {
                   st.pop();
                }
                else if(st.size()>0&&st.top()>abs(arr[i]))
                {
                   continue;
                }
                else
                {
                   st.push(arr[i]);
                }
            }
            else
            {
                st.push(arr[i]);
            }           
        }
        vector<int>v;
        while(st.size())
        {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
