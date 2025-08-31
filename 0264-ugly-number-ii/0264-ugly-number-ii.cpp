class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long>st;
        st.insert(1);
        vector<long long>ans;
        while(ans.size()!=n+1){
            long long uglynum = *st.begin();
            ans.push_back(uglynum);
            st.erase(st.begin());

            st.insert(1LL*uglynum*2);
            st.insert(1LL*uglynum*3);
            st.insert(1LL*uglynum*5);

        }
        return ans[n-1];
    }
};