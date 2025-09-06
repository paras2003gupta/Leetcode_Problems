class Solution {
public:
    int mini = INT_MAX ;
    vector<int>best;
    void check(vector<int>curr){
        sort(curr.begin(),curr.end());
        if(curr.back()-curr[0]<mini){
            mini = curr.back()-curr[0];
            best = curr;
            return;
        }
        return;
        
    }
    void solve(int n , int k , vector<int>&curr, vector<int>&fact){
        if(k==0){
            if(n==1){
                check(curr);
            }
            return;
        }

        for(int i = 0;i<fact.size() ;i++){
            if(n%fact[i]==0){
                curr.push_back(fact[i]);
                solve(n/fact[i],k-1,curr,fact);
                curr.pop_back();
            }
        }
        return;



    }
    vector<int> minDifference(int n, int k) {
        vector<int>curr,fact;
        for(int i = 1 ; i*i<=n ; i++){
            if(n%i==0){
                fact.push_back(i);
                if(i*i<n)
                fact.push_back(n/i);
            }
        }
        // for(auto it:fact){
        //     cout<<it<<" ";
        // }cout<<endl;
        solve(n,k,curr,fact);
        return best;
    }
};