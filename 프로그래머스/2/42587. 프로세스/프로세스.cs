using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] priorities, int location) 
    {
        Queue<(int k, int v)> q = new Queue<(int, int)>();
        
        for(int i = 0; i < priorities.Length; i++)
            q.Enqueue((i, priorities[i]));
        
        int answer = 0;
        
        while (q.Count > 0)
        {
            var c = q.Dequeue();
            
            bool isValid = true;
            
            foreach (var i in q)
            {
                if (i.v > c.v)
                {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid)
            {
                answer++;
                if (c.k == location) 
                    return answer;
            }
            else q.Enqueue(c);
        }
        return 0;
    }
}