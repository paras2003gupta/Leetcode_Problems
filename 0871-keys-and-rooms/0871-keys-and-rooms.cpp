class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        int n = rooms.size();
        q.push(0);
        vector<int>visited(n,0);
        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0;i<sz ; i++){
                int node = q.front();
                q.pop();
                visited[node] = 1;
                for(auto it:rooms[node]){
                    if(!visited[it]){
                        
                        q.push(it);
                    }
                }
            }
        }
        for(auto it:visited){
            if(it==0){
                return false;
            }
            
        }
        return true;
    }
};