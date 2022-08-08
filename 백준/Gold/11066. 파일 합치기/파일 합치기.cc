#include <iostream>
#include <climits> 
// #include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t=0;t<T; t++){
    int N;
    int *cables, *cumul_val;
    int **time;
    int sum, j;
    cin >> N;

    cables = new int [N+1];
    cumul_val = new int [N+1];
    time = new int *[N+1];
    cumul_val[0] = 0;

    for(int i=1; i<=N; i++){
      cin >> cables[i];
      cumul_val[i] = cumul_val[i-1]+cables[i];
      time[i] = new int [N+1];
    }

    for(int interval=1; interval<N; interval++){
      for(int i=1; i<=N-interval; i++){
        j = i+interval;
        time[i][j] = INT_MAX;
        sum = cumul_val[j]-cumul_val[i-1];

        for(int k=i; k<j; k++){
          time[i][j] = min(time[i][j], time[i][k]+time[k+1][j]+sum);
        }
      }
    }
    
    cout << time[1][N]<<"\n";
    }
}
