#include <iostream>
#include <cmath>
using namespace std;

int answer;
int div_val = 16769023;
int main() {
  int n;
  cin >> n;
  if(n%2==1){
    n=n+1;
  }

  int pow_val = n/2;
  if(pow_val<23){
    cout << pow(2,pow_val);
  }
  else{
    answer=pow(2,24)-div_val;
    for(int i=25; i<=pow_val; i++){
      answer*=2; 
      if(answer>div_val){
        answer-=div_val;
      }
    }
    cout << answer;
  }
}