class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int,vector<int>,greater<int>>pq; //minHeap.
        while(n>0){
            int dgt = n%10;
            n/=10;
            pq.push(dgt);
            while(pq.size()>2){
                pq.pop();
            }
        }
        int ans = 1;
        while(!pq.empty()){
            ans*=pq.top();
            pq.pop();
        }
        return ans;
    }
};