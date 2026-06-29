class Solution {
public:
void solve(vector<int>& nums,vector<int>&ans,int i,vector<vector<int>> &subset){
    sort(nums.begin(),nums.end());
    if(i==nums.size()){
        subset.push_back({ans});
        return;
    }
    ans.push_back(nums[i]);
    solve(nums,ans,i+1,subset);
    ans.pop_back();
    int index = i+1;
    while(index<nums.size()&& nums[index]==nums[index-1]){
        index++;
    }
    solve(nums,ans,index,subset);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>subset;
        solve(nums,ans,0,subset);
        return subset;
    }
};