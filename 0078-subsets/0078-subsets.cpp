class Solution {
public:
void solve(vector<int>& nums,vector<int> &ans,int i,vector<vector<int>>&subset){
    if(i== nums.size()){
        subset.push_back(ans);
        return;
    }
    ans.push_back(nums[i]);
    solve(nums,ans,i+1,subset);
    ans.pop_back();
    solve(nums,ans,i+1,subset);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>subset;
        solve(nums,ans,0,subset);
        return subset;
    }
};