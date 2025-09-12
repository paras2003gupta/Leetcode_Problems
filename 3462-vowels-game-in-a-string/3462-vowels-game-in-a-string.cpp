class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt =0;
        for(auto it:s){
            if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u'){
                cnt++;
            }
        }
        if(cnt==0){
            return false;
        }
        if(cnt%2==1){
            return true;
        }
    return true;
    }
};