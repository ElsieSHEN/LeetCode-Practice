
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        unordered_map<int, int> map;
        int counter = 0;
        map[counter] = -1;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i] == 1) counter ++;
            if (nums[i] == 0) counter --;
            if (map.count(counter)) {
                int prevIdx = map[counter];
                maxLength = max(maxLength, i-prevIdx);
            } else {
                map[counter] = i;
            }
        } return maxLength;
    } 
};