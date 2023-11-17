#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//dfs深搜
class Solution{
private:
    //x-1, y+0表示向上搜索
    //x+1, y+0表示向下搜索
    //x+0, y-1表示向左搜索
    //x+0, y+1表示向右搜索
    int direction[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}}; //x + direction[0][i], y + direction[1][i] 代表四个方向
    void dfs(vector<vector<char>>& grid, int x, int y){  //x表示第几行，y表示第几列
        int n = grid.size(), m = grid[0].size();
        grid[x][y] = '0'; //只有满足if(grid[i][j] == '1')条件时（即grid[x][y]是陆地时）才调用dfs函数，所以已经访问过该陆地，不能重复访问，需要将当前位置置为'0'
        for(int i = 0; i < 4; i++){  //向上下左右四个方向搜索
            int next_x = x + direction[0][i], next_y = y + direction[1][i]; //下一个方向：i=0表示向上搜索，i=1表示向下搜索，i=2表示向左搜索，i=3表示向右搜索
            if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue; //下一个位置不能超出grid的边界
            if(grid[next_x][next_y] == '1') dfs(grid, next_x, next_y); //如果下一个位置还是陆地，就继续搜索
        }
    }
public:
    int numIslands(vector<vector<char>>& grid){
        int n = grid.size(); //grid的行数
        if(n == 0) return 0; //grid为空，岛屿数量为0
        int m = grid[0].size(), result = 0;
        for(int i = 0; i < n; i++){ //遍历grid的每一行
            for(int j = 0; j < m; j++){ //遍历grid的每一列
                if(grid[i][j] == '1'){ //如果grid[i][j]是陆地，说明是一个岛屿，岛屿数量加1
                    result++;
                    dfs(grid, i, j); //继续搜索与grid[i][j]上下左右相连的陆地
                }
            }
        }
        return result;
    }

};
int main(){
    Solution s;
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};
    cout << "岛屿数量为：" << s.numIslands(grid) << endl;
}




//bfs广搜
class Solution{
private:
    //x-1, y+0表示向上搜索
    //x+1, y+0表示向下搜索
    //x+0, y-1表示向左搜索
    //x+0, y+1表示向右搜索
    int dire[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};  //x + direction[0][i], y + direction[1][i] 代表四个方向
    void bfs(vector<vector<char>>& grid, int x, int y){
        int n = grid.size(), m = grid[0].size();
        queue<pair<int ,int>> myque;
        myque.push({x, y});
        grid[x][y] = '0';  //只有满足if(grid[i][j] == '1')条件时（即grid[x][y]是陆地时）才调用bfs函数并将其入队，所以已经访问过该陆地，不能重复访问，需要将当前位置置为'0'
        while(!myque.empty()){
            pair<int ,int> cur = myque.front(); //取出队首元素
            myque.pop();  //取出队首元素后将其出队
            //广度搜索体现在：将当前位置的上下左右这一层的陆地都入队，由于队列先进先出的特性，会先搜索完当前位置的上下左右这一层，到下一个位置时，再搜索下一个位置的上下左右的一层
            //在图上就像一圈一圈，向外搜索
            for(int i = 0; i < 4; i++){  //向上下左右四个方向搜索
                int next_x = cur.first + dire[0][i], next_y = cur.second + dire[1][i]; //下一个方向：i=0表示向上搜索，i=1表示向下搜索，i=2表示向左搜索，i=3表示向右搜索
                if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;  //下一个位置不能超出grid的边界
                if(grid[next_x][next_y] == '1'){ //如果下一个位置还是陆地，就将其入队，并将其置为'0'，表示已经访问过
                    myque.push({next_x, next_y});
                    grid[next_x][next_y] = '0';
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid){
        int n = grid.size(); //grid的行数
        if(n == 0) return 0; //若grid为空，说明岛屿数量为0
        int m = grid[0].size(); //grid的列数
        int result = 0;  //统计岛屿数量
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    result++;
                    bfs(grid, i, j);
                }
            }
        }
        return result;
    }


};
int main(){
    Solution s;
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};
    cout << "岛屿数量为：" << s.numIslands(grid) << endl;
}
