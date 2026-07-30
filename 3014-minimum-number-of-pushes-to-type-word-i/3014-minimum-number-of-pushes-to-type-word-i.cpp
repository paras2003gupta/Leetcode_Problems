class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int totalpush = 0;

        for(int i = 0;i<n ;i++){
            totalpush+=(i/8) +1;
        }
        return totalpush;
    }
};