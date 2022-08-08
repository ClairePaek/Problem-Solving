#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// int increase[50001];
int ans;
vector <int> pick, pick2;

int my_lower_bound(vector<int>& lis, int lis_index, int target) {
  int left = 0, right = lis_index;
  while (left < right) {
    int mid = (left + right) / 2;
    if (lis[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return right;
}

int main() {
    int N, mid;
    int *card;

    scanf("%d", &N);
    card = new int [N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &card[i]);
    }

    for (int i = 0; i < N; i++) {
      if (pick.empty()|| card[i] > pick.back()){
        pick.push_back(card[i]); 
        // increase[i] = pick.size();
      }
      else{
        // int minimum = 0;
        int maximum = pick.size()-1;
        int result_index = my_lower_bound(pick, maximum, card[i]);
        // if(increase[i]==0){
        // if(mid != maximum)
          pick[result_index] = card[i]; 
        //   increase[i] = minimum+1;
        // }
      }
    }

  cout << pick.size();
}

