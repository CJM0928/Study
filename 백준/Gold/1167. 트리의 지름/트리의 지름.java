import java.util.*;

public class Main {

    int N;

    Scanner kb;

    boolean [] visited;

    int [] distance;

    ArrayList<Edge>[] adj;

    class Edge{
        int Node;

        int value;

        Edge(int Node , int value){
            this.Node = Node;
            this.value = value;
        }
    }

    private void FindDiameter(){
        kb = new Scanner(System.in);

        N = kb.nextInt();

        visited = new boolean[N+1];
        distance = new int[N+1];
        adj = new ArrayList[N+1];

        for(int i=1; i<=N; i++){
            adj[i] = new ArrayList<Edge>();     // ArrayList<ArrayList<Edge>>
        }

        for(int i=0; i<N; i++){
            int j = kb.nextInt();      // index
            while(true){
                int node =  kb.nextInt();
                if(node == -1){
                    break;
                }
                int value =  kb.nextInt();
                adj[j].add(new Edge(node,value));
            }
        }

        kb.close();

        BFS(1);
        int Max = 1;

        for(int i=2; i<=N; i++){
            if(distance[Max] < distance[i]){
                Max = i;
            }
        }

        visited = new boolean[N+1];
        distance = new int[N+1];

        BFS(Max);

        Arrays.sort(distance);

        System.out.println(distance[N]);
    }

    private void BFS(int Start){
        Queue<Integer> Q = new LinkedList<>();
        Q.add(Start);
        visited[Start] = true;

        while(!Q.isEmpty()){
            int adjNode = Q.poll();
            for(Edge E : adj[adjNode]){
                int n = E.Node;
                int v = E.value;
                if(!visited[n]){
                    visited[n] = true;
                    Q.add(n);
                    distance[n] = distance[adjNode] + v;
                }
            }
        }
    }

    public static void main(String[] args){
        Main App = new Main();

        App.FindDiameter();
    }
}
