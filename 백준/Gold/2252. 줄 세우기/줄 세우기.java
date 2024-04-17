import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    Scanner kb;

    ArrayList<Integer>[] adj;

    int [] count;

    int n,m;

    private void lineUp(){
        kb = new Scanner(System.in);

        n = kb.nextInt();
        m = kb.nextInt();

        adj = new ArrayList[n+1];
        for(int i=0; i<=n; i++){
            adj[i] = new ArrayList<Integer>();
        }

        count = new int[n+1];

        for(int i=0; i<m; i++){
            int node1 = kb.nextInt();
            int node2 = kb.nextInt();

            adj[node1].add(node2);
            count[node2]++;
        }

        BFS();
    }

    private void BFS(){
        Queue<Integer> Q = new LinkedList<>();

        for(int i=1; i<=n; i++) {
            if (count[i] == 0) {
                Q.add(i);
            }
        }

        while(!Q.isEmpty()){
            int adjnode = Q.poll();
            System.out.print(adjnode + " ");
            for(int node : adj[adjnode]){
                count[node]--;
                if(count[node] == 0){
                    Q.add(node);
                }
            }
        }
    }

    public static void main(String[] args) {
        Main App = new Main();

        App.lineUp();
    }
}
