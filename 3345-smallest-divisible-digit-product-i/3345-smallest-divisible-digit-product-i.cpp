class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int temp = i;
            int prod = 1;
            while(temp){
                int dig = temp%10;
                prod *= dig;
                temp/=10;
            }
            if(prod%t==0){
            return i;
            break;
        }
        }
        return -1;
    }
};