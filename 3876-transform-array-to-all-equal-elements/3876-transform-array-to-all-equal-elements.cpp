class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>temp = nums;
        int cnt = 0;
        for(int i = 0;i<n-1 ; i++){
            if(temp[i]==-1){
                temp[i]*=-1;
                temp[i+1]*=-1;
                cnt++;
            }
        }
        if(cnt<=k&&temp[n-1]!=-1){
            return true;
        }
        temp = nums;

        int cnt1=0;
        for(int i = 0;i<n-1 ; i++){
            if(temp[i]==1){
                temp[i]*=-1;
                temp[i+1]*=-1;
                cnt1++;
            }
        }
        if(cnt1<=k&&temp[n-1]!=1){
            return true;
        }
        return false;
    }
};