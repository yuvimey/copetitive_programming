//
// Created by Gili on 16/11/2021.
//
#include <vector>

using namespace std;

//KMP Algorithm – Linear Time Pattern Searching O(n+m)
//uses the fact that when ever we get a mismatch we already know some characters already match

//for example:
//text = "aaaa"
//pattern = "aaa"
//we will compare first three characters naively
// then for the second window we will only compare the forth character since we already
// know the first two match

//Notice: = lps = longest proper prefix which is also a suffix
// for example a proper prefix of "a" is only ""
// the lps of "aa" is "a"

//lps is used to determine how many characters can be skipped

template <typename T>
class KMP {
public:
    vector<T>& pattern;
    vector<int> lps;

    KMP(vector<T>& pattern) : pattern(pattern) {
        computeLPS();
    }

    void computeLPS() {
        int m = pattern.size();
        lps = vector<int>(m);

        int len = 0;
        //proper prefix which is also a suffix of string of len 1 is always 0
        lps[0] = 0;
        int i = 1;
        //lps is being calculated sequentially
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                //if the next char is equal to the previous
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(const vector<T>& txt) {
        int m = pattern.size();
        int n = txt.size();
        vector<int> res;

        int i = 0; // index for txt
        int j = 0; // index for pattern
        while (i < n) {
            if (pattern[j] == txt[i]) {
                j++;
                i++;
            }

            if (j == m) {
                //a match was found
                res.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && pattern[j] != txt[i]) {
                if (j != 0) j = lps[j - 1]; //in this case we can skip some characters
                else i = i + 1; //no characters were a match so none to skip
            }
        }

        // res is a vector s.t. s[i] is the index of starting patter
        return res;
    }
};