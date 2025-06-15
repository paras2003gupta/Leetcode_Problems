class Solution {
public:
    int findPairs(vector<int>& num, int k) {
        unordered_map<int,int>mp;
        set<int>stw;
        for(auto it:num){
            stw.insert(it);
            mp[it]++;
        }
        vector<int>nums;
        for(auto it:stw){
            nums.push_back(it);
            
        }
        
        int cnt = 0;
        if(k==0){
            for(auto it:mp){
                if(it.second>1) cnt++;
                
            }return cnt;
        }

        for(int i = 0 ; i<nums.size() ; i++){
            
            if(mp.find(nums[i]+k)!=mp.end()){
                cnt++;
                
            }

        }
        return cnt;
    }
};