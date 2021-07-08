class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        for (int i=0, j=n-1, pos=n-1; i<=j;) {
            if (nums[i]*nums[i] < nums[j]*nums[j]) {
                answer[pos] = nums[j] * nums[j];
                j--;
            } else {
                answer[pos] = nums[i] * nums[i];
                i++;
            } 
            pos--;
        }
        return answer;
    }
};

// 双指针