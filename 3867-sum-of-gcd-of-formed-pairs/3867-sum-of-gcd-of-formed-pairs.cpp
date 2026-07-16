class Solution {
public:
    int gcdOfTwoNums(int a , int b){
        return b==0?a:gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        vector<int>prefixLargest(n);
        for(int i = 0;i<n;i++){
            
            maxi = max(maxi,nums[i]);
            prefixLargest[i]=max(maxi,nums[i]);

        }
        vector<int>gcdArr(n);
        for(int i = 0;i<n ;i++){
            gcdArr[i]=gcdOfTwoNums(nums[i],prefixLargest[i]);
        }
        sort(gcdArr.begin(),gcdArr.end());
        long long sum = 0;
        for(auto it:gcdArr)cout<<it<<" ";
        for(int i = 0;i< n/2 ;i++){
            
           
            sum+=gcdOfTwoNums(gcdArr[i],gcdArr[n-i-1]);
            
            
        }
        return sum;

    }
};