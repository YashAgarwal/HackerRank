#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}

int main()
{
    int N, I;
    cin >> N >> I;

    /*
    vector<vector<int> > pairs(N);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
    */

    int *A = new int[N];
    for(int i=0; i<N; i++){
      A[i] = 0;
    }

    //Number of unique countries
    int c = 0;
    for(int i=0; i<I; i++){
      int a, b;
      cin >> a >> b;

      if(A[a] == 0 && A[b] == 0){
        A[a] = ++c;
        A[b] = c
      }
      else if(A[a] != 0 && A[b] == 0){
        A[b] = A[a];
      }
      else if(A[a] == 0 && A[b] != 0){
        A[a] = A[b];
      }
    }

    int *B = new int[c+1];
    for(int i=0; i<=c; i++){
      B[i] = 0;
    }

    for(int i=0 ; i<N; i++){
      B[A[i]]++
    }

    long long result = 0;

    for(int i=0; i<c; i++){
      for(int j=i+1; j<=c; j++){
        result += B[i] * B[j];
      }
    }

    cout << result << endl;
    return 0;
}
