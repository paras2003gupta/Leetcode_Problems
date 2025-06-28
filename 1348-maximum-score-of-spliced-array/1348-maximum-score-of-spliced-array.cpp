class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int>sub1;
        vector<int>sub2;
        int tot1 = 0;
        int tot2= 0;
        for(int i = 0;i<nums1.size() ;i++){
            tot1+=nums1[i];
            tot2+=nums2[i];
            sub1.push_back(nums2[i]-nums1[i]);
            sub2.push_back(nums1[i]-nums2[i]);
        }
        int max_sum1 = 0; 
        int curr_sum = 0;
        for(int i = 0;i<nums1.size() ; i++){
            curr_sum+=sub1[i];
            max_sum1 = max(max_sum1,curr_sum);
            if(curr_sum<0){
                curr_sum = 0;
            }
        }
        curr_sum = 0;
        int max_sum2 = 0;
        for(int i = 0;i<nums1.size() ; i++){
            curr_sum+=sub2[i];
            max_sum2 = max(max_sum2,curr_sum);
            if(curr_sum<0){
                curr_sum = 0;
            }
        }
        tot1+=max_sum1;
        tot2+=max_sum2;

        return max(tot1,tot2);


    }
};