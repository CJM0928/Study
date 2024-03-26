import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    BufferedReader br;

    int V,E;

    ArrayList<ArrayList<Integer>> adj;

    boolean [] visited;

    boolean arrive = false;

    private void Find() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        
        V = Integer.parseInt(input[0]);
        E = Integer.parseInt(input[1]);

        visited = new boolean[V];

        adj = new ArrayList<ArrayList<Integer>>(V);

        for(int i=0; i<V; i++){
            adj.add(new ArrayList<Integer>());
        }
        
        for(int i=0; i<E; i++){
            input = br.readLine().split(" ");
            
            // 무방향 그래프
            adj.get(Integer.parseInt(input[0])).add(Integer.parseInt(input[1]));
            adj.get(Integer.parseInt(input[1])).add(Integer.parseInt(input[0]));
        }

        for(int i=0; i<E; i++){
            DFS(i,1);
            if(arrive){
                break;
            }
        }
        
        if(arrive)
            System.out.println(1);
        else 
            System.out.println(0);
    }
    
    private void DFS(int n, int depth){
        if(5 == depth){ // A B C D E 친구
            arrive = true;
            return;
        }

        visited[n] = true;

        for(int a : adj.get(n)){
            if(!visited[a]){
                DFS(a,depth+1);
            }
        }

        visited[n] = false;
    }

    public static void main(String[] args)throws IOException {
        Main App = new Main();

        App.Find();
    }
}
