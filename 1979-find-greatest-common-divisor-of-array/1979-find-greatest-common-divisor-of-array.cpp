class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = nums[0] ;
        int maxi = nums[0];
        for(int i=1;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            mini = min(mini, nums[i]);
        }
        return gcd(mini,maxi);
    }
};