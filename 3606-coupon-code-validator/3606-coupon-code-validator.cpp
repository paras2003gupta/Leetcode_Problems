class Solution {
public:
    bool isValid(string s){
        if(s.size()==0){
            return false;
        }
        for(auto it:s){
            if((it>='A'&&it<='Z')||(it>='a'&&it<='z')||(it>='0'&&it<='9')||it=='_'){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int isStr(string s){
        if(s=="electronics"){
            return 1;
        }
        if(s=="grocery"){
            return 2;
        }
        if(s=="pharmacy"){
            return 3;
        }
        if(s=="restaurant"){
            return 4;
        }
        else{
            return -1;
        }
        
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<int,string>>vaildCoupens;
        for(int i = 0;i<n ;i++){
            if(isActive[i]&&isValid(code[i])&&(isStr(businessLine[i])!=-1)){
                int t = isStr(businessLine[i]);
                vaildCoupens.push_back({t,code[i]});
            }
        }
        sort(vaildCoupens.begin(),vaildCoupens.end());
        vector<string>ans;
        for(auto it:vaildCoupens){
            ans.push_back(it.second);
        }
        return ans;
    }
};