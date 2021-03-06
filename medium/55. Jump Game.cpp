/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.*/

/*
思路：
判断能否到达数组末尾，要时刻更新reach变量，即能到达的最远位置，若当前索引 i > reach，则不能到达 
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        for(int reach = 0;i < nums.size() && i <= reach;i ++) {
            reach = max(reach, i + nums[i]);
        }
        return i == nums.size();
    }
};
