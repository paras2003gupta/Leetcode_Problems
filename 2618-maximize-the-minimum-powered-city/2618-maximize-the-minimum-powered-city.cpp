class Solution {
public:
#define ll long long
    long long maxPower(vector<int>& stations, int r, int k) {
        ll low = *min_element(stations.begin(),stations.end())-1;
        ll high  = accumulate(stations.begin(),stations.end(),0LL)+k+1;
        while(high-low>1){
            ll mid = (high+low)/2;
            if(check(mid,stations,r,k)){
                low = mid;
            }
            else{
                high = mid;
            }
        }

        return low;


    }
    bool check(ll mid , vector<int>stations,ll r , ll k){
        ll n = stations.size();
        ll sum = 0;
        for(int i= 0;i<r ; i++){
            sum+=stations[i];
        }
        vector<ll>add(n,0);
        for(int i= 0;i<n ; i++){
            if(i+r<n){
                sum+=stations[i+r];
            }
            if(sum<mid){
                ll need = mid-sum;
                if(need>k){
                    return false;
                }
                add[min(n-1,i+r)]+=need;
                sum +=need;
                k-=need;
            }
            if(i-r>=0){
                sum-=stations[i-r];
                sum-=add[i-r];
            }
        }
        return true;
    }
};