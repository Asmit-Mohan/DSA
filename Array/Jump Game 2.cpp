class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int c = 0;
        int pos = 0;
        int des = 0;
        
        for(int i=0;i<arr.size()-1;i++)
        {
            des = max(des,i + arr[i]);            
            if(pos == i)
            {
                c++;
                pos = des;
            }
        }
        return c;
    }
};
