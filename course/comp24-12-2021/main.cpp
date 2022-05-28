#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <vector>
#include <set>
#include <list>
#include <bitset>
#include <math.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    vector<int> res(t,0);
    int l, r;
    for (int i = 0; i < t; i++) {
        vector<int> numbers;
        cin >> l >> r;
        if (l == r){
            res[i] = 0;
            continue;
        }
        int x = 1;
        while( x < l){ x = x*2;}
        int y = x;
        while( y*2 <= r){ y = y*2;}
        for(int j = l; j < x; j++) numbers.push_back(j);
        for(int j = y; j < r+1; j++) numbers.push_back(j);
        if(numbers.size() > 0) cout << " numbers[0] = " << numbers[0] << endl;
        else cout << "numbers is empty" << endl;
        bool is_zero  = false;
        int min_number_of_zeros = INT32_MAX;
        int cur_number_of_zeros;
        while(!is_zero) {
            is_zero = true;
            cur_number_of_zeros = 0;
            for (int j = 0; j < numbers.size(); j++) {
                cur_number_of_zeros += 1 - (numbers[j] % 2);
                if( numbers[j] % 2 == 0 && i == 0) cout << "cur " << cur_number_of_zeros << endl;
                numbers[j] = numbers[j] >> 1;
                if( numbers[j]  != 0) is_zero = false;
            }
            if (cur_number_of_zeros < min_number_of_zeros) min_number_of_zeros = cur_number_of_zeros;
        }
        if( y != x) res[i] = min_number_of_zeros +ceil((y-x)/2.0) - 1 ;
        else res[i] = min_number_of_zeros;
        cout << "x: " << x << "  y: " << y << " min_num: " << min_number_of_zeros << " (y-x)/2 = " << (y-x)/2 << endl;
    }

    cout << endl;
    for(int j = 0; j < t; j++){
        cout << res[j] << endl;
    }
}