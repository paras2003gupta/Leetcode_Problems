class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>hashset(n,0);
        int maxlen = 1;
        for(int i = 0 ; i<n ; i++){
            hashset[i] = i;

            for(int prev = 0; prev< i ; prev++){
                if(nums[i]%nums[prev]==0&&dp[i]<1+dp[prev]){
                    dp[i] = 1+dp[prev];
                    hashset[i] = prev;
                    maxlen = max(maxlen,dp[i]);

                }
            }
        }
        int st;
        for(int i = 0 ;i<n ; i++){
            if(dp[i]==maxlen){
                st = i;break;
            }
        }
        vector<int>ans;
        while(st!=hashset[st]){
            ans.push_back(nums[st]);
            st = hashset[st];
        }
        ans.push_back(nums[st]);
        return ans;
    
    }
};