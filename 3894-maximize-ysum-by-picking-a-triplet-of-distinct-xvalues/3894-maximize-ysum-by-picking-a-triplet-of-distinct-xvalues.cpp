class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,int>mp;

        for(int i = 0;i<x.size();i++){
            if(mp.find(x[i])==mp.end()){
                mp[x[i]]=y[i];
            }else{
                mp[x[i]] = max(mp[x[i]],y[i]);
            }
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<endl;
            pq.push(it.second);
            if(pq.size()>3){
                pq.pop();
            }
        }
        int ans = 0;
        if(pq.size()<3){
            return -1;
        }
        else{
            while(!pq.empty()){
                cout<<pq.top()<<" ";
                ans+=pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};