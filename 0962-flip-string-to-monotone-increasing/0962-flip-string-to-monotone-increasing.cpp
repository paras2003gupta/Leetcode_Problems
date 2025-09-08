class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countOnes = 0;
        int ans = s.size();
        int prevAns =0;
        for(int i = 0 ;i<s.size(); i++){
            if(s[i]=='1'){
                countOnes++;
            }
            else{
                
                prevAns = min(prevAns+1,countOnes);


            }
        }
        return prevAns;
    }
};