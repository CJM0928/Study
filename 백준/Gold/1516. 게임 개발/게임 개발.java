import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    Scanner kb;

    int n;

    int[] time;
    int[] buildTime;

    ArrayList<Integer>[] adj;

    int[] count;
    private void gameDevelop(){
        kb = new Scanner(System.in);
        n = kb.nextInt();

        adj = new ArrayList[n+1];
        for(int i=0; i<=n; i++){
            adj[i] = new ArrayList<Integer>();
        }

        time = new int[n+1];
        buildTime = new int[n+1];
        count = new int[n+1];

        for(int i=1; i<=n; i++){
            time[i] = kb.nextInt();

            int value = kb.nextInt();
            while(value != -1) {
                adj[value].add(i);
                count[i]++;
                value = kb.nextInt();
            }
        }

        bfs();

        for(int i=1; i<=n; i++){
            // 각각의 시간까지 최종적으로 더해서 출력
            System.out.println(buildTime[i] + time[i]);
        }
    }

    private void bfs(){
        Queue<Integer> q = new LinkedList<Integer>();

        for(int i=1; i<=n; i++){
            if(count[i] == 0){
                q.add(i);
            }
        }

        while(!q.isEmpty()){
            int node = q.poll();
            for(int adjnode : adj[node]){
                count[adjnode]--;
                buildTime[adjnode] = Math.max(buildTime[adjnode], buildTime[node] + time[node]);
                if(count[adjnode] == 0){
                    q.add(adjnode);
                }
            }
        }
    }

    public static void main(String[] args) {
        Main app = new Main();

        app.gameDevelop();
    }
}
