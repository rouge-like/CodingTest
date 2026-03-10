using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {

    public struct Music
    {
        public int Id;
        public int Plays;
        public Music(int id, int plays)
        {
            Id = id;
            Plays = plays;
        }
    }
    public int[] solution(string[] genres, int[] plays) 
    {
        Dictionary<string, int> sums = new Dictionary<string, int>();
        Dictionary<string, List<Music>> dict = new Dictionary<string, List<Music>>();
        List<int> answer = new List<int>();
        
        for(int i = 0; i < plays.Length; i++)
        {
            string g = genres[i];
            int p = plays[i];
            if(dict.ContainsKey(g))
            {
                sums[g] += p;
            }
            else
            {
                sums.Add(g, p);
                dict.Add(g, new List<Music>());
            }
            dict[g].Add(new Music(i, p));
        }
        var sorted = sums.OrderBy(x => x.Value).ToArray();
        
        for(int i = sorted.Length - 1; i >= 0; i--)
        {
            string g = sorted[i].Key;
            List<Music> list = dict[g];
            list.Sort((a,b) =>{
               if(a.Plays == b.Plays) return a.Id.CompareTo(b.Id);
               return b.Plays.CompareTo(a.Plays); 
            });
            int count = 0;
            foreach(var m in list)
            {
                if(count == 2) break;
                
                answer.Add(m.Id);
                count++;
            }
        }
        return answer.ToArray();
    }
}