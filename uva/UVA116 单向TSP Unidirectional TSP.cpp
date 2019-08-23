    /*
    d[i][j]表示从(i,j)走到最后一列的最优解
    d[i][j] = min {
    	          d[i-1][j+1] 后一列的上面一行
    	          d[i][j+1]   后一列的当前行
    	          d[i+1][j+1] 后一列的下面一行
                  }

    边界 d[i][n] = a[i][n]
    解   min(d[i][1])
    	 Path[i][j] //记录(i,j)位置选择的后续行是哪一个
    */
    #include <iostream>
    #include <algorithm>
    #include <cstring>
    using namespace std;
    int n, m, a[11][101],d[11][101],Path[11][101];
    void print(int x,int y) {
        if(y >= n) {
            cout << '\n';
            return;
        }
        cout << x+1;
        if(y != n-1) cout << ' ';
        print(Path[x][y], y+1);
    }
    int main()
    {
        while (cin>>m>>n)
        {
            for (int i=0; i<m; i++)
                for (int j=0; j<n; j++)
                    cin>>a[i][j];
            memset(d, 127, sizeof(d));
            for(int i=0; i<n; i++)
    			d[i][n-1] = a[i][n-1];
            for (int j=n-2; j>=0; j--)
            {
                for (int i=0; i<m; i++)
                {
                    {
                        int row[3];
                        row[0] = (i-1+m)%m;
                        row[1] = i;
                        row[2] = (i+1)%m;
                        sort(row,row+3);
                        for (int k=0; k<3; k++)
                        {
                            if(d[row[k]][j+1] + a[i][j] < d[i][j]) {
                                d[i][j] = d[row[k]][j+1] + a[i][j];
                                Path[i][j] = row[k];
                            }
                        }
                    }
                }
            }
            int x = 0, ans = 1e9;
            for(int i=0; i<m; i++)
            	if(d[i][0] < ans)
            		ans = d[i][0], x = i;
            print(x, 0);
            cout<<ans<<endl;
        }
        return 0;
    }
