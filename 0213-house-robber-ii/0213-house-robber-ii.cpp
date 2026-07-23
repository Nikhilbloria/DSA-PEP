class Solution {
public:
    int dp[101];

    int solve(int i, int end, vector<int>& nums) {
        if (i > end)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(i + 2, end, nums);
        int skip = solve(i + 1, end, nums);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        // Case 1: Exclude last house
        memset(dp, -1, sizeof(dp));
        int case1 = solve(0, n - 2, nums);

        // Case 2: Exclude first house
        memset(dp, -1, sizeof(dp));
        int case2 = solve(1, n - 1, nums);

        return max(case1, case2);
    }
};