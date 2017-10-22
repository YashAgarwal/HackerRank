#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void dfs(vector< vector<int> > const &A, int i, vector<int> &visited, int &citiesinComponent){
    visited[i] = 1;
    citiesinComponent++;
    for(int j=0; j< A[i].size(); j++){
        if(visited[A[i][j]] == 0){
            dfs(A, i, visited, citiesinComponent);
        }
    }
}

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
        //vector< vector<int> > A(n, vector<int>(0));
        vector<int> A[10];
        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            cout << city_1;
            A[city_1].push_back(city_2);
            A[city_2].push_back(city_1);
        }
        cout << n;

        for(int i=0; i<n; i++){
            for(int j=0; j<A[i].size(); j++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

        //if c_lib <= c_road then make library everywhere
        if(x<=y){
            cout << x*n << endl;
            continue;
        }

        //else
        //Calculate all the components and build 1 library per component

        //array to store if the city has been marked or not
        vector<int> visited(n,0);
        int cost = 0;
        int citiesinComponent = 0;
        for(int i=0; i< n; i++){
            if(visited[i] == 0){
                //a new component starts here
                //start counting the number of cities in this component
                citiesinComponent = 0;
                dfs(A, i, visited, citiesinComponent);
                cost += (citiesinComponent-1) * y + x;
            }
        }

        cout << cost << endl;
    }
    return 0;
}
