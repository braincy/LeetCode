/*Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3*/
   
/*
思路：
从求解子问题的角度来看本题： 
1. 选取一个结点为根，就把结点切成左右子树 
2. 以这个结点为根的可行二叉树数量就是左右子树可行二叉树数量的乘积 
3. 所以总的数量是将以所有结点为根的可行结果累加起来。
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2;i <= n;i ++) {
            for(int j = 0;j < i;j ++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
