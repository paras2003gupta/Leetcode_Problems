class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        
        int ans = -1;
        if(n<=2){
            return "";
        }
        for(int i =1; i<num.size()-1 ; i++){
            if((num[i]==num[i-1]&&num[i]==num[i+1])){
               string an(3,num[i]);
               ans = max(stoi(an),ans);
            }

        }
        if(ans==-1){
            return "";
        }
        if(ans==0){
             string s(3,'0');
             return s;
        }
        return to_string(ans);
    }
};