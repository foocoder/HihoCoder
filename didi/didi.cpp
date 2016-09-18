#include<cstdio>
#include<queue>

using namespace std;
const int MAXDIS=0x7FFFFFFF;
class Point{
    public:
    int x;
    int y;

    Point(int x, int y):x(x), y(y){}
    Point():x(-1),y(-1){}
};

int bfs( int maze[][11], int n, int m, vector<Point> & path){
    Point start(0,0), end(0,m-1);
    int dis[n][m];
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            dis[i][j] = MAXDIS;
        }
    }

    queue<Point> pointQ;
    pointQ.push(start);
    dis[0][0] = 0;

    while(!pointQ.empty()){
        Point cur = pointQ.front();
        pointQ.pop();
        if( cur.x == end.x && cur.y == end.y )
            break;
        //Process Moving
        Point left(cur.x, cur.y-1), right(cur.x, cur.y+1), up(cur.x-1, cur.y), down(cur.x+1, cur.y);
        //Up
        if( up.x>=0 && up.y>=0 && up.x<n && up.y<m && maze[up.x][up.y] != 0 && (dis[up.x][up.y] > dis[cur.x][cur.y]+3) ){
            pointQ.push(up);
            dis[up.x][up.y] = dis[cur.x][cur.y]+3;
        }
        if( down.x>=0 && down.y>=0 && down.x<n && down.y<m && maze[down.x][down.y] != 0 && (dis[down.x][down.y] > dis[cur.x][cur.y]) ){
            pointQ.push(down);
            dis[down.x][down.y] = dis[cur.x][cur.y];
        }
        if( left.x>=0 && left.y>=0 && left.x<n && left.y<m && maze[left.x][left.y] != 0 && (dis[left.x][left.y] > dis[cur.x][cur.y]+1)){
            pointQ.push(left);
            dis[left.x][left.y] = dis[cur.x][cur.y]+1;
        }
        if( right.x>=0 && right.y>=0 && right.x<n && right.y<m && maze[right.x][right.y] != 0 && (dis[right.x][right.y] > dis[cur.x][cur.y]+1) ){
            pointQ.push(right);
            dis[right.x][right.y] = dis[cur.x][cur.y]+1;
        }
    }
    path.push_back(end);
    Point cur = end;
    while( cur.x != start.x || cur.y != start.y ){
        Point left(cur.x, cur.y-1), right(cur.x, cur.y+1), up(cur.x-1, cur.y), down(cur.x+1, cur.y);
        if( up.x>=0 && up.y>=0 && up.x<n && up.y<m && maze[up.x][up.y] != 0 && dis[up.x][up.y]==dis[cur.x][cur.y] ){
            path.push_back(up);
            cur = up;
        }
        else if( down.x>=0 && down.y>=0 && down.x<n && down.y<m && maze[down.x][down.y] != 0 && (dis[down.x][down.y] == dis[cur.x][cur.y]-3) ){
			path.push_back(down);
            cur = down;
        }
        else if( left.x>=0 && left.y>=0 && left.x<n && left.y<m && maze[left.x][left.y] != 0 && (dis[left.x][left.y] == dis[cur.x][cur.y]-1)){
			path.push_back(left);
            cur = left;
        }
        else if( right.x>=0 && right.y>=0 && right.x<n && right.y<m && maze[right.x][right.y] != 0 && (dis[right.x][right.y] == dis[cur.x][cur.y]-1) ){
			path.push_back(right);
            cur = right;
        }
    }
    return dis[end.x][end.y];
}

int main(){
    int n,m,p;
    int maze[11][11];
    while(~scanf("%d %d %d", &n, &m, &p)){
        for( int i=0; i<n; ++i ){
            for( int j=0; j<m; ++j ){
                scanf("%d", & maze[i][j]);
            }
        }
        vector<Point> path;
        int tmp = bfs(maze,n,m, path);
        if(p<tmp){
            printf("Can not escape!\n");
        }
        else{
            int x = path.size();
            printf("%d\n",x);
            for(int i=x-1; i>=0; i--){
                printf("[%d,%d]",path[i].x,path[i].y);
                if(i==0)
                    printf("\n");
                else
                    printf(",");
            }
        }
    }
    return 0;
}
