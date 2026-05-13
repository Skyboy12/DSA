#include <bits/stdc++.h>

using namespace std;

struct maze_matrix{
    vector<vector<int>> matrix;
    int size;
    maze_matrix(int n) : size(n) {
        matrix.resize(n, vector<int>(n));
    }
};

void Solution(const maze_matrix &maze, int x, int y, string &current_route, vector<string> &all_routes){
    int size = maze.size;
    if (x == size - 1 && y == size - 1){
        all_routes.push_back(current_route);
        return;
    }

    if (x < size - 1 && maze.matrix[x + 1][y] == 1){
            current_route.push_back('D');
            Solution(maze, x + 1, y, current_route, all_routes);
            current_route.pop_back();
    }

    if (y < size - 1 && maze.matrix[x][y + 1] == 1){
            current_route.push_back('R');
            Solution(maze, x, y + 1, current_route, all_routes);
            current_route.pop_back();
    }
}

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        maze_matrix maze(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> maze.matrix[i][j];
            }
        }

        if (maze.matrix[0][0] == 0 || maze.matrix[n - 1][n - 1] == 0){
            cout << -1 << '\n';
            continue;
        }

        string current_route;
        vector<string> all_routes;
        Solution(maze, 0, 0, current_route, all_routes);

        if (all_routes.empty()){
            cout << -1;
        } else {
            for (const string &route : all_routes) cout << route << " ";
        }
        cout << endl;
    }
    return 0;
}