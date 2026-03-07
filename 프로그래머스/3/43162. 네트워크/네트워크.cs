using System;
using System.Collections.Generic;

public class Solution {
    bool [] visited = new bool[201];
    int count = 0;
    void BFS(int start, int[,] computers)
    {
        Queue<int> q = new Queue<int>();
        q.Enqueue(start);
        visited[start] = true;
        
        while(q.Count > 0)
        {
            int c = q.Dequeue();
            for(int i = 0; i < computers.GetLength(0); i++)
            {
                if (!visited[i] && computers[c, i] == 1)
                {
                    q.Enqueue(i);
                    visited[i] = true;
                }
            }
        }
        count++;
    }
    public int solution(int n, int[,] computers) {
        
        for(int i = 0; i < n; i++)
        {
            if (!visited[i]) BFS(i, computers);
        }
        return count;
    }
}