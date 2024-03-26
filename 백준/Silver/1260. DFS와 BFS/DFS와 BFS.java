import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    BufferedReader br;

    String[] input;

    int V,E,START;

    boolean [] visited_DFS;

    boolean [] visited_BFS;

    ArrayList<ArrayList<Integer>> adj;

    private void Search() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));

        input = br.readLine().split(" ");
        V = Integer.parseInt(input[0]);
        E = Integer.parseInt(input[1]);
        START = Integer.parseInt(input[2]);

        adj = new ArrayList<ArrayList<Integer>>(V+1);
        visited_DFS = new boolean[V+1];
        visited_BFS = new boolean[V+1];

        for(int i=0; i<=V; i++){
            adj.add(new ArrayList<Integer>());
        }

        for(int i=0; i<E; i++){
            input = br.readLine().split(" ");
            adj.get(Integer.parseInt(input[0])).add(Integer.parseInt(input[1]));
            adj.get(Integer.parseInt(input[1])).add(Integer.parseInt(input[0]));
        }

        // Collections 써서 오름차순 만든다.
        for(int i=0; i<=V; i++){
            Collections.sort(adj.get(i));
        }

        DFS(visited_DFS,START);

        System.out.println();

        BFS(visited_BFS,START);
    }

    private void DFS(boolean[] visited, int START){

        visited[START] = true;

        System.out.print(START +" ");

        for(int adj : adj.get(START)){
            if(!visited[adj]){
                DFS(visited,adj);
            }
        }
    }

    private void BFS(boolean[] visited, int START){
        Queue<Integer> Q = new LinkedList<>();

        Q.add(START);
        visited[START] = true;

        while(!Q.isEmpty()){
            int n = Q.poll();
            System.out.print(n +" ");
            for(int adj : adj.get(n)){
                if(!visited[adj]){
                    Q.add(adj);
                }
                visited[adj] = true;
            }
        }
    }

    public static void main(String[] args)throws IOException {
        Main App = new Main();

        App.Search();
    }
}
