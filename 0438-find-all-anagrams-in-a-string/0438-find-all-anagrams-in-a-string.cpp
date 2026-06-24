class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        unordered_map<char,int>mp1,mp2;
        int k = p.length();
        vector<int> ans;
        if(k>n) return ans;
        for(char c:p){
            mp1[c]++;
        }
        int i =0;
        while(i<k){
            mp2[s[i]]++;
            i++;
        }
        if(mp1==mp2){
            ans.push_back(0);
        }
        while(i<n){
            mp2[s[i]]++;
            mp2[s[i-k]]--;
            if(mp2[s[i-k]]==0){
                mp2.erase(s[i-k]);
            }
            if(mp1==mp2){
                ans.push_back(i-k+1);
            }
            i++;
        }
        return ans;
    }
};