class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water= INT_MIN;

        int left=0,right=height.size()-1;

        int area = min(height[left],height[right])*(right-left);
        max_water=max(max_water,area);
        while(right>left){
            if(height[left]>height[right]){
                right--;
                max_water = max(max_water,min(height[left],height[right])*(right-left));
                
            }else{
                left++;
                max_water= max(max_water,min(height[left],height[right])*(right-left));
                
            }
        }
        return max_water;
    }
};