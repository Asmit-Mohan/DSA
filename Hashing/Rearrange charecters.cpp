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


/*Heap Efficient approach*/

class Solution
{
    public:
    string rearrangeString(string str)
    {
        priority_queue<pair<int,char>> pq;
        int hash[256]={0};
        int count=str.length();
        string ans="";
        for(int i=0;i<str.length();i++)
        {
            hash[str[i]]++;
        }
        for(int i=0;i<256;i++)
        {
            if(hash[i]>0)
            {
                pq.push({hash[i],i});
            }
        }
        if(pq.size()==1&&count>1)
        {
            return "-1";
        }
        pair<int,char> prev={-1,'#'};
        while(count--)
        {
            if(pq.top().first==0)
            {
                return "-1";
            }
            int fre=pq.top().first;
            char letter=pq.top().second;
            ans+=letter;
            pq.pop();
            pq.push(prev);
            prev={fre-1,letter};
        }
        return ans;    
    }
};
