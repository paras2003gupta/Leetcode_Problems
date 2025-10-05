class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return 0;

        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){

            string word = q.front().first;
            int steps = q.front().second;

            q.pop();

            if(word==endWord) return steps;
            
            for(int i = 0 ;i<word.length();i++){
                char original = word[i];
                for(char k = 'a' ; k<='z' ; k++){
                    word[i] = k;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};