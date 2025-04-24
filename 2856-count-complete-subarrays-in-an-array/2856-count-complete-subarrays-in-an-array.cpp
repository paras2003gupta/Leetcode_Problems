class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        int cnt = 0;
        int tot = st.size();
        int n = nums.size();
        for(int i =0;i< n ; i++){
            set<int>st_new ;
            for(int j= i ; j<n ; j++){
                st_new.insert(nums[j]);
                if(st_new.size()==tot){
                    cnt+=(nums.size()-j);
                    break;
                }
            }
        }
        return cnt;
    }
};