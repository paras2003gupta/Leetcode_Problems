class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        for(int i = 0;i<nums.size() ; i++){
            nums[i] = nums[i]%value;
            if(nums[i]<0){
                nums[i] = (nums[i]+value)%value;
            }
            mp[nums[i]]++;
        }
        int ans = nums.size();
        for(int i = 0 ; i<nums.size() ; i++){
            if(mp.find(i%value)!=mp.end()){
                mp[i%value]--;
                if(mp[i%value]==0){
                    mp.erase(i%value);
                }
            }
            else{
                ans = i;
                break;
            }
        }

        return ans;
    }
};