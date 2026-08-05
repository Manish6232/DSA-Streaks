class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int maxsum=0;
        int minLength = INT_MAX;
        int j=0;
        for(int i=0;i<n;i++){
            maxsum += nums[i];
            while(maxsum >= target){
                minLength = min(minLength,i-j+1);
                maxsum -= nums[j];
                j++;
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};