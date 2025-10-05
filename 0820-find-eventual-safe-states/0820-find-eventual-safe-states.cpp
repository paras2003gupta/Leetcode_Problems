class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>indegree(graph.size(),0);
        vector<vector<int>>new_graph(graph.size());
        for(int i = 0;i<graph.size() ; i++){
            for(auto it:graph[i]){
                new_graph[it].push_back(i);
            }
        }
        for(int i = 0 ; i<new_graph.size(); i++){
            for(auto it:new_graph[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i= 0;i<new_graph.size() ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto it:new_graph[top]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};