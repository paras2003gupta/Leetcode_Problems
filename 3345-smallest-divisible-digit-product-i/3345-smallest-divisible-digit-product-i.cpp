class Solution {
public:
    int dgtPdt(int n){
        string s = to_string(n);
        int pdt=1;
        for(int i = 0 ; i<s.size();i++){
            pdt*=(s[i]-'0');
        }
        return pdt;
    }
    int smallestNumber(int n, int t) {
        while(dgtPdt(n)%t!=0){
            n++;
        }
        return n;
    }
};