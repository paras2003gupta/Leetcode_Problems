class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums(cards.begin(),cards.end());
        return solve(nums);
    }

    bool solve(vector<double>&nums){
        if(nums.size()==1){if(fabs(nums[0]-24.0)<1e-6){
            return true;
        }
        else{
            return false;
        }}

        int n = nums.size();
        for(int i = 0;i<n ; i++){
            for(int j = 0;j< n ; j++){
                if(i==j)continue;


                vector<double>next;
                for(int k = 0 ; k<n ; k++){
                    if(k == j || k==i)continue;
                    next.push_back(nums[k]);

                }

                double  a = nums[i];
                double b = nums[j];

                vector<double>res = {a+b,a-b,b-a,a*b};
                if(b!=0) res.push_back((a*1.0)/b);
                if(a!=0) res.push_back((b*1.0/a));

                for(int i = 0;i<res.size(); i++){
                    next.push_back(res[i]);
                    if(solve(next)){
                        return true;
                    }
                    next.pop_back();
                }
            }
        }
        return false;


    }
};