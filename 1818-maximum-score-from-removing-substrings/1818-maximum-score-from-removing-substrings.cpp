class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char>st;
        int ans = 0;
        if(x>y){
            st.push(s[0]);
            int countx =0;
            for(int i = 1 ; i< s.size() ; i++){
                if(!st.empty()&&s[i]=='b'&&st.top()=='a'){
                    st.pop();
                    countx++;
                    continue;
                }
                else{
                    st.push(s[i]);
                }
            }
            string rem = "";
            while(!st.empty()){
                rem+=st.top();
                st.pop();
            }
            int county = 0;
            reverse(rem.begin(),rem.end());
            st.push(rem[0]);
            for(int i = 1 ; i< rem.size() ; i++){
                if(!st.empty()&&rem[i]=='a'&&st.top()=='b'){
                    st.pop();
                    county++;
                    continue;
                }
                else{
                    st.push(rem[i]);
                }
            }
            ans = countx*x+county*y;
            
        }
        else{
            st.push(s[0]);
            int county =0;
            for(int i = 1 ; i< s.size() ; i++){
                if(!st.empty()&&s[i]=='a'&&st.top()=='b'){
                    st.pop();
                    county++;
                    continue;
                }
                else{
                    st.push(s[i]);
                }
            }
            string rem = "";
            while(!st.empty()){
                rem+=st.top();
                st.pop();
            }
            reverse(rem.begin(),rem.end());
            int countx = 0;
            st.push(rem[0]);
            for(int i = 1 ; i< rem.size() ; i++){
                if(!st.empty()&&rem[i]=='b'&&st.top()=='a'){
                    st.pop();
                    countx++;
                    continue;
                }
                else{
                    st.push(rem[i]);
                }
            }
            cout<<countx<<" "<<county<<endl;
            ans = countx*x+county*y;
        }

        return ans;

    }
};