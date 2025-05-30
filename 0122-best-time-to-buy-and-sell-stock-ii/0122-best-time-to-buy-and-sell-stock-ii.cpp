class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>prev(2,0);
        for(int i = n-1; i>=0 ; i--){
            for(int j = 0 ; j<=1 ; j++){
                vector<int>temp(2,0);
                long profit = 0;
                if(j){
                    profit = max(-prices[i]+prev[0],prev[1]);
                }else{
                    profit = max(prices[i]+prev[1],prev[0]);
                }
                temp[j] = profit;
                prev[j] = temp[j];
            }
        }
        return prev[1];
    }
};