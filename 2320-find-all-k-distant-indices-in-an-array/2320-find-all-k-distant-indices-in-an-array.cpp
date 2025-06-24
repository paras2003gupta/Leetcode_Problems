class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int>ans;
        vector<int>keys_index;
        int n = nums.size();
        for(int i = 0 ;i<n ; i++){
            if(nums[i]==key){
                keys_index.push_back(i);
            }
        }
        for(auto j:keys_index){
            int back = j-k;
            int fwd = j+k;

            fwd = min(fwd,n-1);
            back = max(0,back);

            for(int i = back ; i<=fwd ; i++){
                ans.insert(i);
            }
        }
        vector<int>s;
        for(auto it:ans){
            s.push_back(it);
        }
        return s;
    }
};