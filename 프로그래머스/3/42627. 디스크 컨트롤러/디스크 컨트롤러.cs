using System;
using System.Collections.Generic;

public class Solution {

    public class MinHeap
    {
        List<int[]> Heap = new List<int[]>();
        public int Count => Heap.Count;
        public void Push(int[] x)
        {
            Heap.Add(x);
            int current = Count - 1;
            while (current > 0)
            {
                int parent = (current - 1) / 2;
                
                if (Heap[current][1] >= Heap[parent][1]) break;
                
                int[] tmp = Heap[parent];
                
                Heap[parent] = Heap[current];
                Heap[current] = tmp;
                
                current = parent;
            } 
        }
        public int[] Pop()
        {
            int[] root = Heap[0];
            int last = Count - 1;
            
            Heap[0] = Heap[last];
            Heap.RemoveAt(last);
            last -= 1;
            
            int current = 0;
            
            while (true)
            {
                int left = current * 2 + 1;
                int right = current * 2 + 2;
                int next = current;
                
                if (left <= last && Heap[next][1] > Heap[left][1])
                    next = left;
                if (right <= last && Heap[next][1] > Heap[right][1])
                    next = right;
                
                if(next == current) break;
                
                int[] tmp = Heap[current];
                Heap[current] = Heap[next];
                Heap[next] = tmp;
                
                current = next;
            }
            return root;
        }
    }
    public int solution(int[,] jobs) {
        int answer = 0;
        int count = 0;
        int idx = 0;
        int time = 0;
        int n = jobs.GetLength(0);
        
        List<int[]> jobList = new List<int[]>();
        for(int i = 0; i < n; i++) jobList.Add(new int[] { jobs[i, 0], jobs[i, 1]});
        jobList.Sort((a,b) => a[0].CompareTo(b[0]));
        
        MinHeap pq = new MinHeap();
        
        while(count < n)
        {
            while(idx < n && jobList[idx][0] <= time)
            {
                pq.Push(jobList[idx]);
                idx++;
            }
            
            if(pq.Count > 0)
            {
                int[] c = pq.Pop();
                
                time += c[1];
                answer += time - c[0];
                count++;
            }
            else time = jobList[idx][0];
        }
        
        return answer / n;
    }
}