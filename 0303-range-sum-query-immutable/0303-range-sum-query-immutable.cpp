class NumArray {
public:
    vector<int>num,prefixsums;
    NumArray(vector<int>& nums) {
        num= nums;
        prefixsums.push_back(0);
        for(int i = 0;i<nums.size();i++){
            prefixsums.push_back(prefixsums.back()+nums[i]) ;
        }
    }
    
    int sumRange(int left, int right) {
        return prefixsums[right+1]-prefixsums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */