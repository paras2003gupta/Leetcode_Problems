class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i = 0 ;i <n ; i+=3){
            vector<int>a;
            for(int j = i ;j< 3+i ; j++){
                a.push_back(nums[j]);

            }
            if(a.back()-a[0]>k){
                return {};
            }
            else{
                ans.push_back(a);
            }
        }
        return ans;

    }
};