#include <cstdio>
#include <vector>
using namespace std;

int increase[50001];
int decrease[50001];
int sum, max_pick;
vector <int> pick, pick2;

int Insert_point(vector<int>& pick, int end, int card) {
  int low = 0; 
  int high = end;
  while (low<high) {
    int mid =(low+high)/2;
    if (pick[mid]<card) {
      low = mid + 1;
    } 
    else{
      high = mid;
    }
  }
  return high;
}

int main() {
    int N, point;
    int *card;
    scanf("%d", &N);
    card = new int [N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &card[i]);
    }

    for (int i = 0; i < N; i++) {
      if (pick.empty()|| card[i] > pick.back()){
        pick.push_back(card[i]); 
        increase[i] = pick.size();
      }
      else{
        point = Insert_point(pick, pick.size()-1, card[i]);
        pick[point] = card[i];
        increase[i] = point+1;
      }
    }

    for (int i = N-1; i >=0; i--) {
      if (pick2.empty()|| card[i] > pick2.back()){
        pick2.push_back(card[i]); 
        decrease[i] = pick2.size();
      }
      else{
        point = Insert_point(pick2, pick2.size()-1, card[i]);
        pick2[point] = card[i];
        decrease[i] = point+1;
      }
    }
    
    for (int i =0; i <N; i++) {
      sum = decrease[i]+increase[i];
      max_pick = max(max_pick,sum);
    }

    printf("%d",max_pick-1);
    return 0;
}

