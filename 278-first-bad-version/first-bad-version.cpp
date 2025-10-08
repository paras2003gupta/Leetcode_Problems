// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int hi = n;
        int ans = -1;
        while(low<=hi){
            int mid = low +(hi-low)/2;

            if(isBadVersion(mid)){
                ans = mid;
                hi = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};