using System;
using System.Collections.Generic;

public class Solution {
    public bool solution(string s) 
    {
        Stack<char> stack = new Stack<char>();
        
        bool answer = true;
        
        foreach(var c in s)
        {
            if (c == '(')
            {
                if (stack.Count == 0) stack.Push(c);
                else if (stack.Peek() == '(') stack.Push(c);
                else
                {
                    return false;
                }
            }
            else
            {
                if (stack.Count == 0)
                {
                    return false;
                }
                else if (stack.Peek() == '(') stack.Pop();
                else
                {
                    return false;
                }
            }
        }

        return stack.Count == 0;
    }
}