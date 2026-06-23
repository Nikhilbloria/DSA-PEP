class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string c:strs){
            string t  = c;
            sort(t.begin(),t.end());
            mp[t].push_back(c);
        }
        vector<vector<string>>result;
        for(auto e:mp){
            result.push_back(e.second);
        }
        return result;
    }
};