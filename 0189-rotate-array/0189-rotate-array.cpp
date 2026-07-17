class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>brr(n);
        for(int i = 0 ; i<n ; i++){
            brr[(i+k)%n] = nums[i];
        }
        nums=brr;
        
    }
};