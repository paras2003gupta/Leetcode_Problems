class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cur = 0;
        vector<int>ans;
        for(int i = 0;i<nums.size() ; i++){
            while(i<nums.size()&&nums[i]==1){
                cur++;
                i++;
            }

            if(i<nums.size()&&nums[i]==0){
                if(cur!=0){
                    ans.push_back(cur);
                    cur = 0;
                }
                ans.push_back(nums[i]);
            }
        }
        if(cur)ans.push_back(cur);
        for(auto it:ans){{
            cout<<it<<" ";
        }}
        if(ans.size()==1){
            return (ans[0]==0)?0:ans[0]-1;
        }
        if(ans.size()==2){
            return max(ans[0],ans[1]);
        }
        int maxi  =INT_MIN;
        for(int i = 0;i<ans.size() ; i++){
            if(ans[i]==0){
                int sum =0; 
                if(i-1>=0){
                    sum+=ans[i-1];
                }
                if(i+1<ans.size()){
                    sum+=ans[i+1];
                }
                maxi = max(maxi,sum);
            }
        }
        return maxi;

    }
};