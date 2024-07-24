/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
/*
Logic:
1-  count all the elements in the string t
2-  iterate through each char of string s one by one 
3-  check if that character is a part of string t
4 - if it is update the hashmap and counter value
5-  if its not then dont update the hashmap and counter value
6-  after updating if the counter reaches 0 means we have all the 
    characters of t covered in the string s and this is one possible answer
    update d 
7-  update the counter vairable if it reaches more than 1 exit the loop


 */
    string minWindow(string s, string t) {
        vector<int>m(128,0);
        int start =0;
        int end =0;
        int counter = t.size();
        int d = INT_MAX;
        int head =0;

        for(auto c: t){
            m[c]++;
        }

        while(end<s.size()){
            if(m[s[end++]] -- >0){
                counter --;
            }
            while(counter == 0){
                if(end - start <d ) {
                    d= end -start;
                    head = start;
                }
                if(m[s[start++]]++ == 0){
                    counter++;
                }
            }
        }
        return d == INT_MAX? "" : s.substr(head, d);

    }
};
// @lc code=end

