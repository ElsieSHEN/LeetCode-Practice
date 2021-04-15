class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int k=2; k<n; k++) {
            dp[k] = max(dp[k-1], nums[k]+dp[k-2]);
        }
        return dp[n-1];
    }
};

/* 动态规划 
 * 第k步的值是 max(第k-1步，第k-2步+nums[k])
 */

/* 关联题目：213. 打家劫舍 II */