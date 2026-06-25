class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(i<n){
            sum+=nums[i];
            while(j<=i&&target<=sum){
                sum -= nums[j];
                ans = min(ans,i-j+1);
                j++;
            }
          i++; 
        }
        return (ans==INT_MAX)?0:ans;
    }
};