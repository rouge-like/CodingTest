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
        List<string> sortedGenres = new List<string>();
        
        for(int i = 0; i < genres.Length; i++)
        {
            string g = genres[i];
            int p = plays[i];
            
            if (sums.ContainsKey(g))
            {
                sums[g] += p;
            }
            else
            {
                sums.Add(g, p);
                dict.Add(g, new List<Music>());
                sortedGenres.Add(g);
            }
            dict[g].Add(new Music(i, p));
        }
        
        sortedGenres.Sort((a,b)=> sums[b].CompareTo(sums[a]));
        
        List<int> answer = new List<int>();
        
        foreach (string g in sortedGenres)
        {
            List<Music> list = dict[g];
            list.Sort((a,b) => 
                      {
                         if (a.Plays == b.Plays) return a.Id.CompareTo(b.Id);
                          return b.Plays.CompareTo(a.Plays);
                      });
            int cnt = 0;
            foreach(Music m in list)
            {
                answer.Add(m.Id);
                cnt++;
                if (cnt == 2) break;
            }
        }
        return answer.ToArray();
    }
}