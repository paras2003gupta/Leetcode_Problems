class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')  return true;

        return false;
    }
    string sortVowels(string s) {
        map<char,int>mp;
        for(int i = 0;i<s.size() ; i++){
            if(isVowel(s[i])){
                mp[s[i]]++;
            }
        }
        string sortedVowel = "AEIOUaeiou";
        string ans = "";
        int j =0;
        for(int i = 0 ;i<s.size(); i++){
            if(!isVowel(s[i])){
                ans+=s[i];
            }
            else{
                while(mp[sortedVowel[j]]==0){
                    j++;
                }
                ans+=sortedVowel[j];
                mp[sortedVowel[j]]--;
            }
        }
        return ans;
    }
};