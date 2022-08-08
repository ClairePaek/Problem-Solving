#include <iostream>
#include<string.h>

using namespace std;

int cursur;

int main() {
  bool istrue;
  int T,N,pt;
  int result = 0;
  char str1[20];
  char str2[20];
  cin >> T; 
  for(int t=0; t<T; t++){
    char **arr;
    int *count;
    cin >> N;
    count = new int [N];
    arr = new char *[N] ;
    for(int n=0; n<N; n++){
      cin >> str1 >> str2;

      if(n==0){
        arr[0] = new char [20];
        strcpy(arr[0] ,str2);
        count[0]++;
  
      }
      else{
        istrue = false;
        for(int i=0; i<=cursur; i++){
          if(strcmp(str2,arr[i])==0){
            istrue = true;
            pt = i;
            break;
          }
        }
        if(istrue == true){
          count[pt]++;
        }
        else{
          cursur++;
          arr[cursur] = new char [20];
          strcpy(arr[cursur],str2);
          count[cursur]++;
        }
      }
    }
    for(int i=0; i<=cursur; i++){
      int curent;
      for(int j=i; j<=cursur; j++){
        if(j==i){
          curent = count[j];
        }
        else{
          curent += curent*count[j];
        }
      }
      result +=curent;
    }
    cout << result << '\n';
    cursur = 0;
    result = 0;
  }
}