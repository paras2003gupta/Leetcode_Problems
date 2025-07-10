class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int>gaps;
        int n = startTime.size();
        int end = eventTime;
        int start = 0;
        gaps.push_back(startTime[0]-start);
        for(int i = 0 ; i<n-1 ; i++){
            gaps.push_back(-endTime[i]+startTime[i+1]);
        }
        gaps.push_back(end-endTime[n-1]);
        int maxi  =INT_MIN;
        vector<int>sorted_gaps = gaps;
        sort(sorted_gaps.begin(),sorted_gaps.end());
        int i = 0;
        for(; i<gaps.size()-1 ; i++){
            int sum = gaps[i]+gaps[i+1];
            
                int toAdjust = endTime[i]-startTime[i];
                int cnt = gaps.size()-(lower_bound(sorted_gaps.begin(),sorted_gaps.end(),toAdjust)-sorted_gaps.begin());
                if(toAdjust<=gaps[i]){
                    cnt--;
                }
                if(toAdjust<=gaps[i+1]){
                    cnt--;
                }

                if(cnt>0){
                    sum+=toAdjust;
                }

                maxi = max(maxi,sum);
            
        }
        return maxi;
    }
};