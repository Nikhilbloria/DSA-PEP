class Solution {
public:
int n;
int t[13][10001];
    const int INF = 1e9;

    int solve(int i,int amount,vector<int>& coins){
                if(amount==0){
            return 0;
        }
        if(i==n){
            return INF;
        }

        int take = INF;
        int skip = 0;
        if(t[i][amount]!=-1){
            return t[i][amount];
        }
        if(amount>=coins[i]){
            take = 1+solve(i,amount-coins[i],coins);
        }
        skip = solve(i+1,amount,coins);
        return t[i][amount] = min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        memset(t,-1,sizeof(t));
        int ans= solve(0,amount,coins);
        return (ans==INF)?-1:ans;
    }
};