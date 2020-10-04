#include <cstdio>
#include <cmath>

int TC;
int N, M;
int binary[27];

int main(int argc, char** argv){
    scanf("%d", &TC);
    for(int i=0; i<TC; i++){
        scanf("%d %d", &N, &M);

        for(int k=26; k>=0; k--){
            binary[k] = 0;
            if(pow(2, k) <= M){
                binary[k] = 1;
                M -= pow(2, k);
            }
        }

        bool isContinue = true;

        for(int k=0; k<N; k++){
            if(binary[k] == 0){
                isContinue = false;
                break;
            }
        }

        if(!isContinue){
            printf("#%d OFF\n", i+1);
        }
        else{
            printf("#%d ON\n", i+1);
        }
    }
    return 0;
}