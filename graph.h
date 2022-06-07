#include <vector>
#ifndef GRAPH_H
#define GRAPH_H
using namespace std;


class graph
{
public:
    vector<vector<int> > g;
    graph();
    graph(int N,int M){
        //参数输入生成的迷宫大小

        //初始化迷宫
        g = vector<vector<int> >(2*N + 1,vector<int>(2 * M + 1,1));

        for (int i = 0;i<(2*N+1);++i){
            for (int j = 0;j<(2*M+1);++j){
                if (i % 2 == 0 && j % 2 == 0){
                    g[i][j] = 0;//表示格子
                }
            }
        }
    }

};

#endif // GRAPH_H
