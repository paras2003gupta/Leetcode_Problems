class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nge(nums2.size());
        stack<int>st;
        st.push(nums2[nums2.size()-1]);
        nge[nums2.size()-1] = -1;
        for(int i = nums2.size()-2 ; i>=0 ; i--){

            while(!st.empty()&&nums2[i]>st.top()){
                st.pop();
            }
            if(!st.empty()&&nums2[i]>st.top()){

               st.push(nums2[i]);
               nge[i] = -1;

            }
            else{
                if(st.empty()){
                    st.push(nums2[i]);
                    nge[i] = -1;
                    
                }
                else {
                nge[i] = st.top();
                st.push(nums2[i]);}
            }
        }
        unordered_map<int,int>mp;
        for(int i = 0 ; i< nums2.size() ; i++){
            mp[nums2[i]] = nge[i];
        }
        vector<int>ans;
        for(int i = 0 ; i<nums1.size(); i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};