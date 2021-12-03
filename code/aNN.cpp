/*
P1038 [NOIP2003 提高组] 神经网络
I
输入文件第一行是两个整数 n（1 \le n \le 1≤n≤100）和 p。接下来 n 行，每行 2 个整数，第 i+1 行是神经元 i 最初状态和其阈值（Ui），非输入层的神经元开始时状态必然为 00。再下面 PP 行，每行由 2 个整数 i,ji,j 及 1 个整数 W_{ij}W 
ij
 ，表示连接神经元 i,ji,j 的边权值为 W_{ij}W 
ij
 。
O
输出文件包含若干行，每行有 2 个整数，分别对应一个神经元的编号，及其最后的状态，2 个整数间以空格分隔。仅输出最后状态大于 0 的输出层神经元状态，并且按照编号由小到大顺序输出。

*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define N 102
#define M N*N
#define Low 0
#define High 1
using namespace std;
queue<int> qlg;
struct GoogleChrome{
    int to, vao, from, next;
} e[M];
struct copyable{
    int num, vao;
} chao[N];
int h, i, m, n, t, u, v, w, x, c[N], head[N];
bool out[N], visited[N];
int cnt = Low, tot = Low;
bool bomb(copyable last, copyable next){
    return last.num < next.num;
}
void build(int u, int v, int w){
    cnt++;
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].vao = w;
    e[cnt].next = head[u];
    printf("e[%d].next = head[%d]=%d\n", cnt, u, head[u]);
    head[u] = cnt;
    printf("head[%d] = %d\n", u, cnt);
}
int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; ++i){
        head[i] = 0, out[i] = false;
        cin >> c[i] >> x;
        if(c[i])
            qlg.push(i), visited[i] = true;
        else{
            c[i] -= x, visited[i] = false;
            cout << c[i] << "我是你爹\n";
        }

    }
    for (i = 1; i <= m; ++i){
        cin >> u >> v >> w;
        build(u, v, w);
        out[u] = true;
    }
    while(!qlg.empty()){
        h = qlg.front(), qlg.pop();
        for (i = head[h]; i; i = e[i].next)
        {
            if(c[e[i].from] <= 0)
                continue;
            t = e[i].to;
            c[t] += (e[i].vao * c[h]);
            if(!visited[t])
                qlg.push(t), visited[t] = true;
        }
    }
    for (i = 1; i <= n; ++i)
        if(c[i] && !out[i]){
            tot++;
            chao[tot].num = i,chao[tot].vao = c[i];
        }
    if(!tot){
        printf("NULL");
        return 0;
    }
    sort(chao + 1, chao + tot + 1, bomb);
    for (i = 1; i <= tot; ++i)
        printf("%d %d\n",chao[i].num, chao[i].vao);
    // GoogleChrome popp[40];
    // typedef char string[1000];
    // string a = "hello,你怎么好意思呢";
    // cout<<"a的类型是："<<abi::__cxa_demangle(typeid(a).name(),0,0,0)<<endl;
    return 0;
}
