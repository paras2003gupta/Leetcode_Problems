class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        vector<int>keys_index;
        int n = nums.size();
        for(int i = 0 ;i<n ; i++){
            if(nums[i]==key){
                keys_index.push_back(i);
            }
        }
        int st = 0;
        for(auto j:keys_index){
            int back = j-k;
            int fwd = j+k;

            fwd = min(fwd,n-1);
            back = max(0,back);
            while(st<=fwd){
                if(st>=back)ans.push_back(st);
                st++;
            }
            
        }
        
        return ans;
    }
};