import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    BufferedReader br;

    ArrayList<Integer>[] adj;

    int N;  // 노드

    int M;  // 엣지

    int K;  // 거리 정보

    int X;  // 출발 번호

    int [] visited;


    List<Integer> answer;
    private void Findutil() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));

        String [] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        K = Integer.parseInt(input[2]);
        X = Integer.parseInt(input[3]);

        answer = new ArrayList<>();
        adj = new ArrayList[N+1];

        visited = new int[N+1];

        for(int i=0; i<=N; i++){
            visited[i] = -1;
        }

        for(int i=0; i<=N; i++){
            adj[i] = new ArrayList<Integer>();
        }

        for(int i=0; i<M; i++){
            input = br.readLine().split(" ");
            int node1 = Integer.parseInt(input[0]);
            int node2 = Integer.parseInt(input[1]);
            adj[node1].add(node2);
        }

        DFS(X);

        for(int i=0; i<=N; i++){
            if(visited[i] == K){
                answer.add(i);
            }
        }

        if (answer.isEmpty()){
            System.out.println(-1);
        }else{
            Collections.sort(answer);
            for(int temp : answer){
                System.out.println(temp);
            }
        }
    }

    private void DFS(int start){
        Queue<Integer> Q = new LinkedList<Integer>();
        Q.add(start);
        visited[start]++;
        while (!Q.isEmpty()){
            int node = Q.poll();
            for(int i : adj[node]){
                if(visited[i] == -1){
                    visited[i] = visited[node] + 1;
                    Q.add(i);
                }
            }
        }
    }


    public static void main(String[] args)throws IOException {
        Main App = new Main();

        App.Findutil();
    }
}
