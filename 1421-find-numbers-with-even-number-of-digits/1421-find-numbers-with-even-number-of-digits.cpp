class Solution {
    private:
    int iseven(int nums){
        string n = to_string(nums);
        return n.size()%2==0;
    }
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto it:nums){
            if(iseven(it)){
                cnt++;
            }
        }
        return cnt;
    }
};