class Solution {
public:
    using ll = long long;
    #define MOD 1000000007
    int specialTriplets(vector<int>& nums) {
        unordered_map<ll,ll>leftmp;
        unordered_map<ll,ll>rightmp;

        for(int i = 0;i<nums.size(); i++){
            rightmp[nums[i]]++;
        }
        ll cnt = 0;
        for(int i = 0;i<nums.size();i++){
            rightmp[nums[i]]--;
            if(rightmp[nums[i]]==0){
                rightmp.erase(nums[i]);
            }
            int k = nums[i]*2;
            if((leftmp.find(k)!=leftmp.end())&&(rightmp.find(k)!=rightmp.end())){
                cnt = (cnt+ (1LL*(leftmp[k]*rightmp[k])%MOD)%MOD)%MOD;
                
            }
            leftmp[nums[i]]++;
        }
        return cnt;

    }
};