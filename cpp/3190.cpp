#include <iostream>
#include <queue>
using namespace std;

int **board;
int N, K, L, Time;
queue <pair<int, int> > body, tmpbody;
queue <pair<int, char> > directions;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0}; //우 좌 하 상 
const int Left[] = {3, 2, 0, 1}, Right[] = {2, 3, 1, 0};

void move(int dir){
    Time ++;
    int nx, ny;
    nx = body.back().second + dx[dir]; //머리를 이동시킨다.
    ny = body.back().first + dy[dir]; 
    
    if(nx < 0 || nx > N-1 || ny < 0 || ny > N-1) //벽에 부딫히면 끝
        return;
    
    tmpbody = body; 
    while (!tmpbody.empty()){ //자신과 만나면 끝
        if(tmpbody.front().first == ny && tmpbody.front().second == nx)
            return;
        tmpbody.pop();
    }

    body.push(make_pair(ny, nx)); //움직인 머리 넣고
    if(board[ny][nx] == 0){ //사과가 없으면 길이 동일
        body.pop();
    }
    else
        board[ny][nx] = 0; //사과가 있으면 길이 1증가 후 사과 없앤다. 

    int ndir; 
    if(!directions.empty() && directions.front().first == Time){ //시간이 맞으면 
        if(directions.front().second == 'L')
            ndir = Left[dir];
        else
            ndir = Right[dir];
        
        directions.pop();
    }
    else
        ndir = dir;

    move(ndir);
}


void Solution(){
    move(0);
    cout << Time <<'\n';
}

void Input(){
    cin >> N;
    board = new int *[N];
    for(int n=0; n<N; n++){
        board[n] = new int [N];
    }

    cin >> K;
    for(int k=0; k<K; k++){
        int x, y;
        cin >> y >> x;
        board[y-1][x-1] = 1;
    }

    cin >> L;
    for(int l=0; l<L; l++){
        int second;
        char dir;
        cin >> second >> dir;
        directions.push(make_pair(second, dir));
    }

    body.push(make_pair(0,0));
}

int main(){
    Input();
    Solution();
}