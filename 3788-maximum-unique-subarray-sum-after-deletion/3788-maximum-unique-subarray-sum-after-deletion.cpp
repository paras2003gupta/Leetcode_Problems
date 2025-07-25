class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st;
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        if(maxi<0){
            return maxi;
        }
        for(auto it:nums){
            if(it<0)continue;
            st.insert(it);
        }

        int sum = 0;
        for(auto i:st){
           sum+=i;
        }
        return sum;
    }
};