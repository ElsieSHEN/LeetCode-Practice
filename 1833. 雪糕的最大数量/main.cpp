class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for (int i=0; i<costs.size(); i++) {
            int cost = costs[i];
            if (coins >= cost) {
                coins -= cost;
                count ++;
        } else {
            break;
            }
        }
        return count;    
    }
};

// 错误思路：dp
即便dp，最大数量不变，因此直接排序+求和即可