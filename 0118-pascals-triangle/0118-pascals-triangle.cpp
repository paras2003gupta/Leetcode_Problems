class Solution {
    private:
    int NCR(int n , int r){
        int res = 1;
        if(n==0&&r==0){
            return 1;
        }
        for(int i = 0 ; i< r ; i++){
            res = res * (n-i);
            res = res/(i+1);
        }
        return res;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i =0 ; i< numRows ; i++){
            vector<int>ch;
            for(int j = 0 ; j<=i ; j++){
                
                ch.push_back(NCR(i,j));
            }
            ans.push_back(ch);
        }
        return ans;


    }
};