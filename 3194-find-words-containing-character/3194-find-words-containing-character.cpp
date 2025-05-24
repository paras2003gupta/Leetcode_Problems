class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        for(int i = 0 ; i<words.size(); i++){
            string it = words[i];
            for(auto chr:it){
                if(chr==x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};