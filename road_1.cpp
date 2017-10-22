
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int q;
    cin >> q;

    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        int x;
        int y;
        cin >> n >> m >> x >> y;

        //Build a Adjacency List
        vector< vector<int> > A(n);
        //vector<int> A[10];
        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            cout << city_1;
            A[city_1].push_back(city_2);
            A[city_2].push_back(city_1);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<A[i].size(); j++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
