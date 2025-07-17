#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();

        if (n == 0) return 0; // If needle is empty

        for (int i = 0; i <= h - n; i++) {
            if (haystack.substr(i, n) == needle)
                return i;
        }

        return -1;
    }
};
