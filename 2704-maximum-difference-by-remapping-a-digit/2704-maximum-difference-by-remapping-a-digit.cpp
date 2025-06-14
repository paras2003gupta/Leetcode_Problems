class Solution {
public:
    int minMaxDifference(int num) {
        string n = to_string(num);
        char dgttoberep = '$';
        char dgttoberep1 = '$';
        for(int i = 0;i<n.size() ;i++){
            if(n[i]-'0'<9){
                dgttoberep = n[i];
                break;
            }
        }
        for(int i = 0;i<n.size() ;i++){
            if(n[i]-'0'>0){
                dgttoberep1 = n[i];
                break;
            }
        }
        string maxi = "";
        string mini = "";
        for(int i = 0 ;i<n.size() ; i++){
            if(n[i]==dgttoberep){
                maxi+='9';
                continue;
            }
            

            maxi+=n[i];
        
        }
        for(int i = 0 ;i<n.size() ; i++){
            
            if(n[i]==dgttoberep1){
                mini+='0';
                continue;
            }
            
           
            mini+=n[i];
        }
        int maximum  = stoi(maxi);
        int minimum = stoi(mini);
        cout<<maximum<<" "<<minimum<<endl;
        
        
        
        if(dgttoberep=='$'){
            return num;
        }
        
        return maximum-minimum;

    }
};