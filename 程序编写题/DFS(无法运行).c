 #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    const int inf = 0x7f7f7f7f;
    int d[50];
    int a[][7] = {
        {0},
        {0, 0, 2, 10, 5, 3, -1},
        {0, -1, 0, 12, -1, -1, 10},
        {0, -1, -1, 0, -1, 7, -1},
        {0, 2, -1, -1, 0, 2, -1},
        {0, 4, -1, -1, 1, 0, -1},
        {0, 3, -1, 1, 0, 2, 0},
    };
    int x, y;
    int res;
    int used[10];
    int ans = inf;
    int ansp;
    int ansd[50];

    void dfs(int now, int cost, int p) {
      if (now == x) {
        if (cost < ans) {
          ans = cost;
          for (int i = 0; i < p; i++) {
            ansd[i] = d[i];
          }
          ansp = p;
        }
        return;
      }
      for (int i = 1; i <= 6; i++) {
        if (i == y) {
          continue;
        }
        if (used[i] == 0 && a[now][i] >= 0) {
          used[i] = 1;
          d[p] = i;
          dfs(i, cost + a[now][i], p + 1);
          used[i] = 0;
        }
      }
    }

    int main() {
      static char emp[] = "";
      static char col[] = ", ";
      scanf("%d%d", &x, &y);
      if (x == 5) {
        printf("0\n[]\n");
        return 0;
      }
      if (y == 5) {
        printf("1000\n[]\n");
        return 0;
      }
      d[0] = 5;
      used[5] = 1;
      dfs(5, 0, 1);
      char *p = emp;
      if (ans == inf) {
        printf("1000\n[]\n");
      } else {
        printf("%d\n[", ans);
        for (int i = 0; i < ansp; i++) {
          printf("%s%d", p, ansd[i]);
          p = col;
        }
        printf("]\n");
      }
    }
