//this code includes printing of the Longest Increasing subsequence also

class Solution {
    private:
    int solve(vector<int>&nums,int i,int prev,vector<vector<int>>&dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];

        int len = solve(nums,i+1,prev,dp);

        if(prev==-1||nums[i]>nums[prev]){
            len = max(len,1+solve(nums,i+1,i,dp));
        }
        return dp[i][prev+1]= len;
    }
    int solveTab(vector<int>&nums){
        int n = nums.size();
        vector<vector<int>>dp(nums.size()+2,vector<int>(nums.size()+10,0));

        for(int i = n-1 ; i>=0 ; i--){
            for(int prev = i-1 ; prev>=-1 ; prev--){
                int len = dp[i+1][prev+1];
                if(prev==-1||nums[i]>nums[prev]){
                    len = max(len,1+dp[i+1][i+1]);
                }
                dp[i][prev+1] = len;
            }
        }
        return dp[0][0];
    }
    int spaceOpt(vector<int>&nums){
        int n = nums.size();
        vector<int>ahead(nums.size()+3,0);
        for(int i = n-1 ; i>=0 ; i--){
            vector<int>curr(nums.size()+2,0);
            for(int prev = i-1 ; prev>=-1 ; prev--){
                int len = ahead[prev+1];
                if(prev==-1||nums[i]>nums[prev]){
                    len = max(len,1+ahead[i+1]);
                }
                curr[prev+1] = len;
            }
            ahead = curr;
        }
        return ahead[0];
    }
    int method2(vector<int>&nums){
        vector<int>dp(nums.size(),1);
        vector<int>hash(nums.size(),0);
        for(int i = 0 ; i<nums.size() ; i++){
            hash[i]=i;
        }

        int maxi = 1;
        for(int i = 0; i<nums.size() ; i++){
            for(int prev = 0 ; prev<i ; prev++){
                if(nums[prev]<nums[i]){
                    hash[i] = prev;
                    dp[i] = max(dp[i],1+dp[prev]);
                    maxi = max(maxi,dp[i]);
                }
            }
        }
        int start;
        for(int i = 0;i<nums.size() ; i++){
            if(dp[i]==maxi){
                start = i;
            }
        }
        vector<int>ans;
        while(hash[start]!=start){
            ans.push_back(nums[start]);
            start = hash[start];
        }
        ans.push_back(nums[start]);
        reverse(ans.begin(),ans.end());
        cout<<"One of the Longest Increasing solution is ->";
        for(auto it:ans){
            cout<<it<<" ";
        }cout<<endl;
        return maxi;
    }
    int method3BS(vector<int>&nums){
            vector<int>temp;
            temp.push_back(nums[0]);

            for(int i = 1; i<nums.size() ; i++){
                if(nums[i]>temp.back()){
                    temp.push_back(nums[i]);
                }else{
                    int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                    temp[ind] = nums[i];
                }
            }
            return temp.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return method3BS(nums);
        return method2(nums);
        return solveTab(nums);
        return solve(nums,0,-1,dp);
    }
};