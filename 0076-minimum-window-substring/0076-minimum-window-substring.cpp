class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char,int>mp;
        for(char c:t){
            mp[c]++;
        }
        int i=0;
        int f =-1;
        int d =mp.size();
        int j =0;
        int len = 1e8;
        while(i<n){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                d--;
            }
            while(d==0){
                if(len>i-j+1){
                    len = i-j+1;
                    f =j;
                }
                mp[s[j]]++;
                if(mp[s[j]]==1){
                    d++;
                }j++;
            }
            i++;
        }
    if(f==-1){
        return "";
    }
    return s.substr(f,len);
    }
};