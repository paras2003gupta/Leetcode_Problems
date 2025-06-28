class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_pro = INT_MIN;
        int pdt = 1;
        for(int i = 0;i<nums.size() ; i++){
            pdt*=nums[i];
            max_pro = max(max_pro,pdt);
            if(pdt==0){
                pdt=1;
            }
        }
        pdt = 1;
        for(int i= nums.size()-1 ; i>=0 ;i--){
            pdt*=nums[i];
            max_pro = max(max_pro,pdt);
            if(pdt==0){
                pdt = 1;
            }
        }
        return max_pro;
    }
};