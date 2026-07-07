class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = to_string(n);
        string non_zer = "";
        for(auto it : str){
            if(it!='0'){
                non_zer+=it;
            }
        }
        long long back_to_int = 0;
        int sum=0;
        for(auto it:non_zer){
            back_to_int*=10;
            sum+=(it-'0');
            back_to_int+=(it-'0');
        }
        return back_to_int*sum;

    }
};