class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discount) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discount.begin(),discount.end(),greater<int>());
        

        double tot = 0;
        int i =0;
        for(;i < min(discount.size(),prices.size()) ; i++){

            double p = prices[i] * (double)((100-discount[i])/(double)100);
            tot+=p;

        }
        while(i<prices.size()){
            tot+=prices[i];
            i++;
        }
        return tot;

    }
};