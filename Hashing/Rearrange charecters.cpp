/* Time:- O(Nlogn) Space :- O(26) */

/*General hashing approach*/

class Solution
{
    public:
    char maxCount(int hash[])
    {
        int max=-1;
        char temp;
        for(int i=0;i<26;i++)
        {
            if(hash[i]>max)
            {
                max=hash[i];
                temp=i+'a';
            }
        }
        return temp;
    }
    string rearrangeString(string str)
    {
        int hash[26]={0};
        int count=str.size();
        for(int i=0;i<str.length();i++)
        {
            hash[str[i]-'a']++;
        }
        char maxEle=maxCount(hash);
        int maxFre=hash[maxEle-'a'];
        if(maxFre>(count+1)/2)
        {
            return "-1";
        }
        int idx=0;
        string ans(count,' ');
        while(maxFre--)
        {
            ans[idx]=maxEle;
            idx+=2;
            hash[maxEle-'a']--;
        }
        
        for(int i=0;i<26;i++)
        {
            while(hash[i]>0)
            {
                idx=(idx>=count)?1:idx;
                ans[idx]=i+'a';
                idx+=2;
                hash[i]--;
            }
        }
        return ans; 
    }
};

/* Heap Efficient Approach */

class Solution
{
    public:
    string rearrangeString(string str)
    {
        string ans = "";
        unordered_map<char,int> mp;
        priority_queue<pair<int,char> > pq;
        
        for(auto x : str)
        {
            mp[x]++;
        }
        
        for(auto x : mp)
        {
            pq.push({x.second,x.first});
        }
        
        while(pq.size()>1)
        {
            pair<int,char> temp1 = pq.top();
            pq.pop();
            pair<int,char> temp2 = pq.top();
            pq.pop();
            
            ans += temp1.second;
            ans += temp2.second;
            
            if(--temp1.first>0)
            {
               pq.push(temp1); 
            }
            
            if(--temp2.first>0)
            {
               pq.push(temp2); 
            }
        }
        if(pq.size())
        {
            if(pq.top().first == 1)
            {
                ans += pq.top().second;
            }
            else
            {
                return "-1";
            }
        }
        return ans;    
    }
};
