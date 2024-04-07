import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    BufferedReader br;

    BufferedWriter bw;
    
    boolean [] visited;
    
    int [] count;
    
    ArrayList<Integer>[] adj;

    int N,M;
    private void hacking() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        adj = new ArrayList[N + 1];
        count = new int[N + 1];
        
        for (int i = 1; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }

        // A가 B를 신뢰하는경우, B -> A 가능
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int node1 = Integer.parseInt(st.nextToken());
            int node2 = Integer.parseInt(st.nextToken());
            adj[node1].add(node2);
        }

        for (int i = 1; i <= N; i++) {
            visited = new boolean[N + 1];
            Queue<Integer> Q = new LinkedList<Integer>();
            Q.add(i);
            visited[i] = true;

            while(!Q.isEmpty()){
                int num = Q.poll();
                for(int adjnode : adj[num]){
                    if(!visited[adjnode]){
                        visited[adjnode] = true;
                        count[adjnode]++;       // 인접노드 방문할때마다 1 증가
                        Q.add(adjnode);
                    }
                }
            }
        }

        int Max = Integer.MIN_VALUE;
        for (int i = 1; i <= N; i++) {
            Max = Math.max(Max,count[i]);
        }

        for (int i = 1; i <= N; i++) {
            if (Max == count[i]) {
                bw.write(i + " ");
            }
        }

        bw.flush();
        bw.close();
    }

    private void BFS (int start) {
        Queue<Integer> Q = new LinkedList<Integer>();
        Q.add(start);
        visited[start] = true;

        while(!Q.isEmpty()){
            int num = Q.poll();
            for(int adjnode : adj[num]){
                if(!visited[adjnode]){
                    visited[adjnode] = true;
                    count[adjnode]++;       // 인접노드 방문할때마다 1 증가
                    Q.add(adjnode);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();
        
        App.hacking();
    }
}
