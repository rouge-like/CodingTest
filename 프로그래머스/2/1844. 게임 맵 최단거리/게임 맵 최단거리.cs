using System;
using System.Collections.Generic;
class Solution {
    public class Pos{
        public int y;
        public int x;
        public int cnt;
        public Pos(int ny, int nx, int ncnt)
        {
            y = ny;
            x = nx;
            cnt = ncnt;
        }
    }
    public int solution(int[,] maps) {
        Queue<Pos> q = new Queue<Pos>();
        q.Enqueue(new Pos(0,0,1));
        int answer = 0;
        int[] dy = new int[4] {1,-1,0,0};
        int[] dx = new int[4] {0,0,1,-1};
        int n = maps.GetLength(0);
        int m = maps.GetLength(1);
        maps[0, 0] = 0;
        while(q.Count > 0)
        {
            var pos = q.Dequeue();
            if (pos.y == n - 1 && pos.x == m - 1) return pos.cnt;
            for(int i = 0; i < 4; i++)
            {
                int ny = pos.y + dy[i];
                int nx = pos.x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (maps[ny, nx] == 0) continue;
                maps[ny, nx] = 0;
                q.Enqueue(new Pos(ny, nx, pos.cnt + 1));
            }
        }
        return -1;
    }
}