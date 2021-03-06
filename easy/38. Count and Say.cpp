/*The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"*/

/*
题意：
n=1时输出字符串1；n=2时，数上次字符串中的数值个数，因为上次字符串有1个1，所以输出11；
n=3时，由于上次字符是11，有2个1，所以输出21；n=4时，由于上次字符串是21，有1个2和1个1，所以输出1211。
依次类推，写个countAndSay(n)函数返回字符串。
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 0)  return "";
        string res = "1";
        while(-- n) {
            string cur = "";
            for(int i = 0;i < res.length();i ++) {
                int count = 1;
                while(i + 1 < res.length() && res[i] == res[i + 1]) {
                    i ++;   count ++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};
