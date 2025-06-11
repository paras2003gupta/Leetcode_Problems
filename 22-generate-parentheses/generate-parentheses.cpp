class Solution {
    private:
    void solve(int n,vector<string>&ans,string &temp,int i, int j){
        if(i==n&&j==n){
            ans.push_back(temp);
            return;
        }
        if(i+1<=n){
            temp.push_back('(');
            solve(n,ans,temp,i+1,j);
            temp.pop_back();
        }
        if(j+1<=n&&j+1<=i){
            temp.push_back(')');
            solve(n,ans,temp,i,j+1);
            temp.pop_back();
        }


    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        solve(n,ans,temp,0,0);
        return ans;
    }
};