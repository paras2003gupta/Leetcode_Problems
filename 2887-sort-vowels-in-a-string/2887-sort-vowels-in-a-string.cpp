class Solution {
public:
    string sortVowels(string s) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:s){
            if(it=='A'||it=='E'||it=='I'||it=='O'||it=='U'||it=='a'||it=='e'||it=='i'||it=='o'||it=='u'){
                pq.push(it);
            }
        }
        for(int i = 0;i<s.size() ; i++){
            char it = s[i];
            if(it=='A'||it=='E'||it=='I'||it=='O'||it=='U'||it=='a'||it=='e'||it=='i'||it=='o'||it=='u'){
                int top = pq.top();
                pq.pop();
                char c = (char)top;
                s[i] = c;
            }
        }
        return s;
    }
};