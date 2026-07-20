class Solution {
public:
    int t[301][5001];
    int n;
    int solve(int i, int amount, vector<int>& coins){
        if(amount==0){
            return 1;
        }
        if(i==n){
            return 0;
        }
        if(t[i][amount]!=-1){
            return t[i][amount];
        }
        int take =0;
        int skip =0;
        if(amount>=coins[i]){
            take = solve(i,amount-coins[i],coins);
        }
        skip = solve(i+1,amount,coins);
        return t[i][amount] = skip+take;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(t,-1,sizeof(t));
        return solve(0,amount,coins);
    }
};