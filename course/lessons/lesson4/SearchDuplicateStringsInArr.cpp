//
// Created by Gili on 03/01/2022.
//

#include <vector>
#include <string>
#include "ComputeHash.cpp"

using namespace std;

vector<vector<int>> group_identical_strings(vector<string> const & s)
{
    int n = s.size();
    //each pair will represent hash, index on word
    //Notice: me no collisions in hash
    vector<pair<long long , long>> hashes(n);
    for (int i = 0; i < n; i++)
    {
        //compute hash for each word
        hashes[i] = {ComputeHash(s[i]), i}
    }

    //sort hashes vector so same hashes will be sequential
    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for(int i = 0; i < n; i++)
    {

        if (i == 0 || hashes[i].first != hashes[i-1].first)
        {
            //if current hash is different from previous, create a new group
            groups.emplace_back();
        }
        //insert current hash to the last group
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}