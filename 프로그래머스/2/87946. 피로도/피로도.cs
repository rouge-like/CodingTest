using System;
using System.Collections.Generic;

public class Solution {
    int maxCount = 0;
    bool[] visited;
    void DFS(int current, int[,] dungeons, int count){
        if (maxCount < count) maxCount = count;
        
        for(int i = 0; i < dungeons.GetLength(0); i++){
            if(!visited[i] && current >= dungeons[i, 0]){
                visited[i] = true;
                
                DFS(current - dungeons[i, 1], dungeons, count + 1);
                
                visited[i] = false;
            }
        }
    }
    public int solution(int k, int[,] dungeons) {
        int n = dungeons.GetLength(0);
        visited = new bool[n];
        
        DFS(k, dungeons, 0);
        
        return maxCount;
    }
}