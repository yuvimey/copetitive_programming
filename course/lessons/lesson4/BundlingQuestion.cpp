//
// Created by Gili on 03/01/2022.
//

#include "trie.cpp"

//In this question we are asked to divide N words into K groups
//s.t. the sum of scores of each group is maximized
//score = the longest prefix shared by all words in the group

//the solution is using trie

int Bundling()
{
    ios::sync_with_stdio(0);
    int T; //number of test cases
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n,k;//n = number of words, k = size of groups
        cin>>n>>k;
        //len of words is at most 2000000 hence -> max_len of trie is 2000005
        trie tr(2000005);
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            //add each word to trie
            tr.add(s);
        }
        //first node - 0
        // k - size of group
        //depth of node - 0
        tr.dfs(0, k, 0);

        cout<<"Case #"<<t<<": ";
        cout<<tr.sum<<endl;
    }
}