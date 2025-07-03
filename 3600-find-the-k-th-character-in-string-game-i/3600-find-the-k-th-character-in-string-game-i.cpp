class Solution {
public:
    char kthCharacter(int k) {
        int n = k-1;
        int i = 0;
        int cnt = 0;
        for(int i = 0;i<11 ;i++){
            if((1<<i)&n){
                cnt++;
            }
        }
        return ('a'+cnt);
    }
};