class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int j = 0;
        int n = nums.size();
        vector<int>g;
        int len = 0;
        while(j<n){
            
            while(j<n&&nums[j]==0){
                j++;
                len++;
            }
            if(j<n&&nums[j]!=0){
                if(len)g.push_back(len);
                len =0;
                j++;
            }
        }
        if(len!=0){
            g.push_back(len);
        }
        long long ans =0;
        for(auto it:g){
            ans += ((1LL*it)*(it+1)/2);
        }
        return ans;
    }
};