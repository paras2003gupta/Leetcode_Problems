class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        int count = 0;
        vector<int>set_elements;
        for(auto it:st){
            set_elements.push_back(it);
        }
        for(int i = 0;i<set_elements.size() ; i++){
            if(set_elements[i]<k){
                return -1;
            }
            else if(set_elements[i]==k){
                return set_elements.size()-1;
            }
            else{
                return set_elements.size();
            }
        }
        return -1;
            
    }
};