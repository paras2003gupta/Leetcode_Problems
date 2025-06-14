class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ans;
        int n = nums2.size();
        vector<int>nge(nums2.size());
        nge[n-1] = -1;
        st.push(nums2[n-1]);
        for(int i = n-2 ; i>=0;i--){
            while(!st.empty()&&st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i] = -1;
            }else{
                nge[i] = st.top();
            }

            st.push(nums2[i]);
        }
        unordered_map<int,int>mp;
        for(int i= 0;i<n ; i++){
            mp[nums2[i]] = nge[i];
        }
        for(auto it:nums1){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};