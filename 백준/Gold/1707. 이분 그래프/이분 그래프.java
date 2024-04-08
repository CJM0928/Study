import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main {


    int K;

    int V;

    int E;

    ArrayList<Integer> [] adj;

    BufferedReader br;

    boolean[] visited;


    boolean check;

    String[] input;

    int[] parent;


    private void determine() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        
        K = Integer.parseInt(br.readLine());        // 테스트케이스 개수
        for(int i=0; i<K; i++){
            input = br.readLine().split(" ");
            V = Integer.parseInt(input[0]);
            E = Integer.parseInt(input[1]);

            visited = new boolean[V+1];
            adj = new ArrayList[V+1];
            parent = new int[V+1];

            check = true;

            for(int j=1; j<=V; j++){
                adj[j] = new ArrayList<Integer>();
            }
            for(int k=0; k<E; k++){
                input = br.readLine().split(" ");
                int node1 = Integer.parseInt(input[0]);
                int node2 = Integer.parseInt(input[1]);
                adj[node1].add(node2);
                adj[node2].add(node1);
            }
            
            for(int s=1; s<V; s++){
                if(check){
                    dfs(s);
                }else{
                    break;
                }
            }
            if(check){
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }
        }

    }

    private void dfs(int start){
        visited[start] = true;

        for(int i : adj[start]){
            if(!visited[i]){
                parent[i] = (parent[start]+1)%2;
                dfs(i);
            }
            else if(parent[i] == parent[start]){
                check = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.determine();
    }
}
