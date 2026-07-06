class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });

        if(intervals.size() <= 1) return intervals.size();
        
        int cnt = 0;
        int start = INT_MAX,end=0;
        for(int i = 1; i < intervals.size(); i++) {

            int startLast = intervals[i][0];
            int endLast = intervals[i][1];
            start = min(start,intervals[i-1][0]);
            end = max(end,intervals[i-1][1]);

            if(start <= startLast && end >= endLast)
                cnt++;
        }

        return intervals.size() - cnt;
    }
};