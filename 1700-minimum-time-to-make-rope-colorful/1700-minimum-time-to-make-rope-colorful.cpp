class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        vector<pair<char,int>>vec;

        for(int i = 0;i<colors.size() ; i++){
            char col = colors[i];
            int time = neededTime[i];
            vec.push_back({col,time});

        }
        int minTot = 0;
        stack<pair<char,int>>st;
        for(auto it:vec){
            char col = it.first;
            int time = it.second;
            if(st.empty()){
                st.push({col,time});
            }else{
                if(st.top().first==col){
                    if(st.top().second>time){
                        minTot+=time;
                        continue;
                    }
                    else{
                        minTot+=st.top().second;
                        st.pop();
                        st.push({col,time});
                    }
                }else{
                    st.push({col,time});
                }

            }
        }
        return minTot;
    }
};