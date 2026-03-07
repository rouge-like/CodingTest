using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.Length];
   
        Stack<int> stack = new Stack<int>();
        for (int i = 0; i < prices.Length; i++) {
            while (stack.Count > 0 && prices[stack.Peek()] > prices[i]) {
                int pastIndex = stack.Pop();
                answer[pastIndex] = i - pastIndex;
            }
            stack.Push(i);
        }

        while (stack.Count > 0) {
            int pastIndex = stack.Pop();
            answer[pastIndex] = prices.Length - 1 - pastIndex;
        }
        
        return answer;
    }
}