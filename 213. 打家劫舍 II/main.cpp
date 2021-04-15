class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // 分类讨论头尾只留一个的情况
        int result1 = rob_try(nums, 0, n-2); // 留头去尾
        int result2 = rob_try(nums, 1, n-1); // 去头留尾
        return max(result1, result2);
    }

    int rob_try(vector<int>& nums, int start, int end) {
        if (start == end) return nums[end];
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);
        for (int k=start+2; k<end+1; k++) {
            dp[k] = max(dp[k-1], nums[k]+dp[k-2]);
        }
        return dp[end];
    }
};

/* 动态规划 
 * 第k步的值是 max(第k-1步，第k-2步+nums[k])
 */

/* 关联题目：198. 打家劫舍 I */