class Solution {
    private:
    bool isPossible(int k,vector<int>& task, vector<int>& workers, int pills, int strength){
        int p = pills;
        int m = workers.size();
        int n = task.size();
    
        deque<int>available;
        int j = m-1;

        for(int i = k-1;  i>=0 ; i--){
            while(j>=m-k&&workers[j]+strength>=task[i]){
                available.push_front(workers[j--]);
            }
            if(available.size()==0) return false;

            if(available.back()>=task[i]){
                available.pop_back();
            }
            else{
                if(p==0)return false;
                p--;
                available.pop_front();
        
            }
        }
        return true;

    }
public:
    int maxTaskAssign(vector<int>& task, vector<int>& workers, int pills, int strength) {
        sort(task.begin(),task.end());
        sort(workers.begin(),workers.end());
        int n = task.size();
        int m = workers.size();
        int lo = 0; int hi = min(n,m);
        int task_completed = 0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(isPossible(mid,task,workers,pills,strength)){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return hi;
    }
};