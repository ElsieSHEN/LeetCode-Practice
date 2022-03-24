// 简单递归，超时
class Solution {
public:
    int numTrees(int n) {
        return count(1, n);
        }
    int count (int lo, int hi) {
        if (lo > hi) return 1;
        int sum = 0;
        for (int i=lo; i<=hi; i++) {
            int left = count(lo, i-1);
            int right = count(i+1, hi);
            sum += left * right;
        }
        return sum;
    }
};

// 动态规划 G[n] = sum F(i,n) i from 1 to n
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n+1, 0);
        G[0] = 1;
        G[1] = 1;
        for (int i=2; i<=n; i++) {
            for (int j=1; j<=i; j++) {
                G[i] += G[j-1] *G[i-j]; // F(i,n)=G(i-1)*G(n-i)
            }
        }
        return G[n];
    }
};

// 纯数学 C_{n+1} = 2(2n+1)/(n+2) * C_n
class Solution {
public:
    int numTrees(int n) {
        long long C = 1;
        for (int i=0; i<n; i++) {
            C = C*2*(2*i+1) / (i+2);
        }
        return (int)C;
    }
};