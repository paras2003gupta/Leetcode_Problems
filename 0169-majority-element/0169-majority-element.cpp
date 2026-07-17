class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int morele = nums[0];
        int fq = 1;
        for(int i  =1 ;i< n ;i++){
            if(morele==nums[i]){
                fq++;
            }
            else{
                fq--;
            }
            if(fq==0){
                fq=1;
                morele =nums[i];
                continue;
            }

        }
        return morele;
    }
};