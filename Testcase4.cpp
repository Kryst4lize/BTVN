//library
#include<math.h>
#include<iostream>
#include<vector>
using namespace std;

//check wether vector out of bound
bool check(vector<vector<int>>map,int x ,int y) {
    if (x < map.size() && y < map[x].size()) {
        return true;
    }
    else return false;
}
void expand(vector<vector<int>>& map, vector<vector<bool>>& occupied, vector<vector<int>> &photomap, int i, int j, int N) {
    if (map[i][j] == N - 1) {
        if (check(map, i, j + 1) && map[i][j + 1] == 0 && occupied[i][j + 1] == false) {
            photomap[i][j + 1] = N-1;
            occupied[i][j + 1] = true;
        }
        if (check(map, i, j - 1) && map[i][j - 1] == 0 && occupied[i][j - 1] == false) {
            photomap[i][j - 1] = N-1;
            occupied[i][j - 1] = true;
        }
        if (check(map, i + 1, j) && map[i + 1][j] == 0 && occupied[i + 1][j] == false) {
            photomap[i + 1][j] = N-1;
            occupied[i + 1][j] = true;
        }
        if (check(map, i - 1, j) && map[i - 1][j] == 0 && occupied[i - 1][j] == false) {
            photomap[i - 1][j] = N-1;
            occupied[i - 1][j] = true;
        }
    }
    else {
        if (check(map, i, j + 1) && map[i][j + 1] == map[i][j] + 1 && occupied[i][j + 1] == false) {
            photomap[i][j + 1] = map[i][j];
            occupied[i][j + 1] = true;
        }
        if (check(map, i, j - 1) && map[i][j - 1] == map[i][j] + 1 && occupied[i][j - 1] == false) {
            photomap[i][j - 1] = map[i][j];
            occupied[i][j - 1] = true;
        }
        if (check(map, i + 1, j) && map[i + 1][j] == map[i][j] + 1 && occupied[i + 1][j] == false) {
            photomap[i + 1][j] = map[i][j];
            occupied[i + 1][j] = true;
        }
        if (check(map, i - 1, j) && map[i - 1][j] == map[i][j] + 1 && occupied[i - 1][j] == false) {
            photomap[i - 1][j] = map[i][j];
            occupied[i - 1][j] = true;
        }
    }
}
//deal with map location
void warmap(vector<vector<int>>& map, int N, int R, int C) {
    //submap to check wether that location are already attack or not
    vector<vector<bool>>occupied(R);
    for (int i = 0; i < R; i++) {
        occupied[i].resize(C,0);
    }
    //create photomap
    vector<vector<int>>photomap(map);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            expand(map, occupied, photomap, i, j, N);
        }
    }
    map = photomap;
}
int mainte4()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //input
    int N, R, C, K;
    do {
        cin >> N >> R >> C >> K;
        vector<vector<int>>map(R);
        for (int i = 0; i < R; i++) {
            map[i].resize(C);
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> map[i][j];
            }
        }
        //ouput
        for (int i = 0; i < K; i++) {
            warmap(map, N, R, C);
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
    } while (N != 0 && R != 0 && C != 0 && K != 0);
    return 0;
}