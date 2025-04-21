class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        vector<long long>prefixArr(d.size());
        prefixArr[0]=d[0];
        for(int i= 1;i<d.size() ; i++){
            prefixArr[i] = 1LL*(prefixArr[i-1]+d[i]); 
        }
        long long  mini = LLONG_MAX;
        long long maxi = LLONG_MIN;
        for(auto it:prefixArr){
            mini = min(mini,it);
            maxi = max(maxi,it);
        }

        int cnt =0;
        for(int i = lower ; i<= upper ; i++){
            if(i+mini>=lower&&i+maxi<=upper){
                cnt++;
            }
            else if(i+mini>=lower&&i+maxi>upper){
                break;
            }
        }
        return cnt;
    }
};