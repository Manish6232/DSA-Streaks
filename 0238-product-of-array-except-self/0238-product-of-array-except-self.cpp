class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
        vector<int> res(n);
        res[0] = 1;
        for(int i=1;i<n;i++){ 
            res[i] = res[i-1]*nums[i-1]; // left product 1,2,6,24
        } 
        int rightPr=1;
        for(int i=n-1;i>=0;i--){ //  1,2,2,6,24 
            res[i] *= rightPr;   //     4,3,2,1 ^|^
            rightPr *= nums[i]; // rightPr _,_,_,24,1
        }
        return res;
    }
};