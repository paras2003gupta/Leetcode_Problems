class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char,int>>st;
        int minTot = 0;
        for(int i = 0;i<colors.size() ; i++){
            char col = colors[i];
            int time = neededTime[i];
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