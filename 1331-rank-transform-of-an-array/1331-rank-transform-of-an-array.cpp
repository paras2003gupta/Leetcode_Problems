class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>st;
        for(auto it:arr){
            st.insert(it);
        }
        map<int,int>mp;
        int rank = 1;
        for(auto it:st){
            mp[it]=rank;
            rank++;
        }
        vector<int>ans(arr.size());
        for(int i = 0 ; i< arr.size() ; i++){
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};