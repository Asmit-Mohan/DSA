/* Time :- O(nlogn) Space :- O(n) */

string maximumFrequency(string s)
{
    stringstream str(s);
    string word;
    map<string,int>mp;
    int fre=0;
    
    while (str>>word)
    {
        mp[word]++;
        fre = max(fre, mp[word]);
    }
    
    stringstream st(s);
    string mx;
    
    while(st >> word)
    {
        if(mp[word] == fre)
        {
            mx=word;
            break;
        }
    }
    
    mx=mx+" "+to_string(fre);
    return mx;
}
