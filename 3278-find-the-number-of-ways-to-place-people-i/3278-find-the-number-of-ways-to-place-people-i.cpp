class Solution {
public:
    bool isTrue(vector<int>&p1,  vector<int>&p2 ,vector<vector<int>>& points ){
        int x1 = p1[0];
        int y1 = p1[1];
        int x2 = p2[0];
        int y2 = p2[1];
        if((x1-x2>=0&&y1<=y2)||(x1<=x2&&y1>=y2)){
            int coorxup = max(x1,x2);
            int cooryup = max(y1,y2);
            int coorxdn = min(x1,x2);
            int coorydn  = min(y1,y2);
            bool flag = true;
            for(auto it:points){
                if(it==p1||it==p2)continue;
                if(it[0] >= coorxdn && it[0] <= coorxup &&it[1] >= coorydn && it[1] <= cooryup){
                    flag = false;
                }
            }
            if(!flag)return false;

            return true;
        }
        return false;
        

        
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int count =0;
        // sort(points.begin(),points.end());
        for(int i= 0; i<points.size()-1 ; i++){
            for(int j = i+1 ; j<points.size();j++){
                vector<int> p1 = points[i];
                vector<int>p2 = points[j];
                if(isTrue(p1,p2,points)){
                    count++;
                }
            }
        }
        return count;
    }
};