using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[,] clothes) 
    {
        Dictionary<string, int> dict = new Dictionary<string, int>();
        
        for(int i = 0; i < clothes.GetLength(0); i++)
        {
            string type = clothes[i, 1];
            
            if (dict.ContainsKey(type)) dict[type] += 1;
            else dict.Add(type, 1);
        }
        
        int answer = 1;
        
        foreach (int a in dict.Values)
        {
            answer *= (a + 1);
        }

        return answer - 1;
    }
}