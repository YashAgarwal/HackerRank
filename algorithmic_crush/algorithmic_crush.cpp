#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int M, N;
    cin >> M >> N;

    vector< vector<long> > v(M, vector<long>(3));

    unordered_map<long, long> C;

    for(int i=0; i<M; i++){
        //Make interval list
        cin >> v[i][0] >> v[i][1] >> v[i][2];

        //Make peak point list
        C[v[i][0]] = 0;
        C[v[i][1]] = 0;
    }

    long max = 0;
    for(auto i=C.begin(); i!= C.end(); i++){
        for(int j=0; j<M; j++){
            if(i->first >= v[j][0] &&  i->first <= v[j][1])
                i->second += v[j][2];
        }
        if(i->second > max) max = i->second;
    }

    cout << max;

    return 0;
}
