/*In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Note:

1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.*/

/*
思路：
使用两个辅助数组，分别表示每个位置与左侧最近距离和与右侧最近距离
最后两数组每个位置对比求出最近的最大距离
*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> left(seats.size()), right(seats.size());
        int index = -1, res = 0;
        for(int i = 0; i < seats.size(); i ++) {
            if(seats[i] == 0) {
                left[i] = index != -1 ? i - index : INT_MAX;
            } else {
                index = i;
                left[i] = 0;
            }
        }
        index = -1;
        for(int i = seats.size() - 1; i >= 0; i --) {
            if(seats[i] == 0) {
                right[i] = index != -1 ? index - i : INT_MAX;
            } else {
                index = i;
                right[i] = 0;
            }
        }
        for(int i = 0; i < seats.size();i ++) {
            res = max(res, min(left[i], right[i]));
        }
        return res;
    }
};
