impl Solution {
    pub fn network_delay_time(times: Vec<Vec<i32>>, n: i32, k: i32) -> i32 {
        const INF: i32 = i32::MAX / 2; // prevent add overflow
        let n = n as usize;
        let mut g = vec![vec![INF; n]; n]; // neighbor matrix

        for t in &times {
            g[t[0] as usize - 1][t[1] as usize - 1] = t[2];
        }

        let mut dis = vec![INF; n];
        dis[k as usize - 1] = 0;
        let mut done = vec![false; n];
        loop {
            let mut x = n;
            for (i, &ok) in done.iter().enumerate() {
                if !ok && (x == n || dis[i] < dis[x]) {
                    x = i;
                }
            }
            if x == n {
                return *dis.iter().max().unwrap();
            }
            if dis[x] == INF {
                // some nodes not reach
                return -1;
            }
            done[x] = true; // min path get
            for (y, &d) in g[x].iter().enumerate() {
                // update x neighbor matrix
                dis[y] = dis[y].min(dis[x] + d);
            }
        }
    }
}
