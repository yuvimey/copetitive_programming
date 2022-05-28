//
// Created by Gili on 09/11/2021.
//

// Trie is a data structure to represent a set of words in a compact way.
// Each node in a trie will count number of words ending at the current node.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>

using namespace std;
typedef long long ll;

class trie{
    // number of nodes in the trie tree
   int max_len;
    //each node in the tree has a map which represent the next step in the tree for a given char
    // this map a char to int. meaning to which node to move next for input char
    vector<unordered_map<char,int>> t; //t[0]['a']=1  means that e(0,1)='a'.
    vector<ll> cnt;
    int szT;
public:
    ll sum; ////this was added for question: Bundling
    trie(int max_len):max_len(max_len),sum(0){
        szT=0;
        t=vector<unordered_map<char,int>>(max_len);
        cnt=vector<ll>(max_len);
    }

    void add(const string& s) {
        //add string s to trie

        int len = s.size();
        //start from root
        int v = 0;
        for (int i = 0; i < len; i++) {
            // c is current char in s
            int c = s[i];
            // c key in map t[v] is exist or created here.
            //if there is no edge from current node to c create a new node representing c
            if (t[v][c] == 0) t[v][c] = ++szT;
            v = t[v][c];
        }
        //arrived to node representing last char in s -> increase counter of words ending at this node
        ++cnt[v];
    }

    int find(const string& s) {
        //find: search for s in the trie, if s is found - return number of occurrences
        int len = s.size();
        // we start in the root
        int v = 0;
        for (int i = 0; i < len; i++) {
            //for each character in s,

            //c current char in s
            int c = s[i];
            //check if there is an edge from current node, v, to the node representing c
            if (t[v][c] == 0) return 0;
            //found number of next node
            v = t[v][c];
        }
        return cnt[v];
    }

    ////this was added for question Bundling
    int dfs(int cur,int group_size,int d)
    {
        //up = number of words in current node
        int up=cnt[cur];
        //loop on neighbors of current node
        for(auto p : t[cur]){
            //run dfs on each child, sum all excess returned from sons
            up+=dfs(p.second,group_size,d+1);
        }
        //calculate number of bundles:
        int teams_number=up/group_size; //we take maximum number of groups of size group_size
        //d is depth of current node = the longest prefix
        sum+=(d*teams_number);
        up-=(teams_number*group_size);
        //up - is number of nodes that were not divided into groups, they are moved upwards to parent node
        return up;
    }
};



//int main()
//{
//    ios::sync_with_stdio(0);
//    trie t(100000);
//    t.add("aviram");
//    t.add("aviram");
//    t.add("avi");
//    cout<<t.find("aviram");
//}
