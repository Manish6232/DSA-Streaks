class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return 0;

        unordered_map<int, int> freq;
        long long windowSum = 0;
        long long ans = 0;

        // Build the first window
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
            freq[nums[i]]++;
        }

        // Check the first window
        if (freq.size() == k)
            ans = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {

            // Remove the leftmost element
            windowSum -= nums[i - k];
            freq[nums[i - k]]--;

            if (freq[nums[i - k]] == 0)
                freq.erase(nums[i - k]);

            // Add the new element
            windowSum += nums[i];
            freq[nums[i]]++;

            // Check if all elements are distinct
            if (freq.size() == k) {
                ans = max(ans, windowSum);
            }
        }

        return ans;
    }
};