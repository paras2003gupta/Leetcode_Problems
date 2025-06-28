class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        int ans = 0;
        for(int i = 0;i<n ;i++){
            ans++;
            if(nums[i]+i>=nums.size()-1){
                break;
            }

            int mx = 0;int go = -1;
            for(int j =i+1;j<=nums[i]+i ; j++){
                if(nums[j]+j>mx){
                    mx = nums[j]+j ;
                    go = j;
                }
            }
            i = go-1;
        }
        return ans;
    }
};