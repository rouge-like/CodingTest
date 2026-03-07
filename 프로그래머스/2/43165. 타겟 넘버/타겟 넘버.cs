using System;
using System.Collections.Generic;

public class Solution {
    int answer = 0;
    public int solution(int[] numbers, int target) {
        DFS(numbers, target, 0, 0);
        return answer;
    }
    public void DFS(int[] numbers, int target, int depth, int sum){
        if (depth == numbers.Length){
            if (sum == target)
            {
                answer++;
            }
            return;
        }
        
        DFS(numbers, target, depth + 1, sum + numbers[depth]);
        DFS(numbers, target, depth + 1, sum - numbers[depth]);
    }
}