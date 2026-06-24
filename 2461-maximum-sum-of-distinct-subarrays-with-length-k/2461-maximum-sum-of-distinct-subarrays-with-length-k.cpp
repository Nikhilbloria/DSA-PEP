class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        long long sum = 0;
        long long ans = 0;
        unordered_map<int,int>mp;
        while(i<k&&i<n){
            sum+=nums[i];
            mp[nums[i]]++;
            i++;
        }
        if(mp.size()==k){
            ans = sum;
        }
        while(i<n){
            sum+=nums[i];
            mp[nums[i]]++;
            sum-=nums[i-k];
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
            if(mp.size()==k){
                // ans=sum;
                ans = max(ans,sum);
            }
            i++;
        }
    return ans;
    }
};