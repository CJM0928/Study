import java.io.*;
import java.util.ArrayList;

public class Main {

    BufferedReader br;

    BufferedWriter bw;
    
    ArrayList<ArrayList<Integer>> adj;
    
    boolean [] visited;
    
    int V;  // 정점
    
    int E;  // 간선

    int count = 0;
    
    
    private void DFSutil() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        V = Integer.parseInt(input[0]);
        E = Integer.parseInt(input[1]);

        visited = new boolean[V+1];
        
        adj = new ArrayList<ArrayList<Integer>>(V);

        for(int i=1; i<=V+1; i++){
            adj.add(new ArrayList<Integer>());
        }
        
        // Edge 만들어주기
        for(int i=1; i<=E; i++){
            input = br.readLine().split(" ");
            int m = Integer.parseInt(input[0]);
            int n = Integer.parseInt(input[1]);
            
            // 무방향
            adj.get(m).add(n);
            adj.get(n).add(m);
        }

        for(int i=1; i<=V; i++){
            if(!visited[i]){
                DFS(visited,i);
                count++;
            }
        }

        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(count +" ");

        bw.flush();
    }

    private void DFS(boolean[] visited, int start){
        visited[start] = true;

        for(int adjNode : adj.get(start)){
            if(!visited[adjNode]){
                DFS(visited,adjNode);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();
        
        App.DFSutil();
    }
}
