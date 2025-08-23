class Solution {
public:
    bool checkunique(string s) {
        set<char> st;
        for (auto it : s) {
            
            st.insert(it);
        }
        return st.size()== s.size();
    }

    int solve(vector<string>& arr, int i, string s,map<pair<int,string>,int>&mp) {
        if (i == arr.size()) {
            return s.size();
        }
        if(mp.find({i,s})!=mp.end()){
            return mp[{i,s}];
        }
        int maxlen = 0;

        // include arr[i] if valid
        string t = s + arr[i];
        if (checkunique(t)) {
            maxlen = max(maxlen, solve(arr, i + 1, t,mp));
        }

        // exclude arr[i]
        maxlen = max(maxlen, solve(arr, i + 1, s,mp));
        return mp[{i,s}] =  maxlen;
    }

    int maxLength(vector<string>& arr) {
        map<pair<int,string>,int>mp;
        return solve(arr, 0, "",mp);
    }
};
