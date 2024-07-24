#include <bits/stdc++.h>
using namespace std;

// Substring Template To Solve Most Problems
// A-Z  = 65-90
// a-z = 97-122

int findSubstring(string s){
    vector<int>map(128,0);
    int counter; // to check whether substring is valid
    int begin =0, end =0; // 2 pointers to point at head and tail
    int d; // length of substring

    for(){
        // initialize the hashmap here
    }
    while(end<s.size()){
        if(map[s[end++]] -- ?){
            // modify the counter
        }

        while(/*counter condition */){
            // update d here if finding minimum
            // increase begin to make it invalid/valid again
            if(map[s[begin++]]++ ?){
                // modify the counter here
            }
        }
        // update d here if finding maximum
    }
    return d;
}