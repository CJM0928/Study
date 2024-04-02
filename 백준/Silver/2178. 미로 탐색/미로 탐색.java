import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    // 시계방향
    int [] dx = {0,1,0,-1};
    int [] dy = {1,0,-1,0};
    BufferedReader br;

    StringTokenizer st;

    int N,M;

    int [][] maze;
    
    boolean [][] visited;

    private void Search() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        
        maze = new int[N][M];
        visited = new boolean[N][M];

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            String num = st.nextToken();
            for(int j=0; j<M; j++){
                maze[i][j] = Integer.parseInt(num.substring(j,j+1));
            }
        }

        BFS(0,0);
        System.out.println(maze[N-1][M-1]);
    }

    private void BFS(int n, int m){
        Queue<int[]> Q = new LinkedList<>();
        Q.add(new int[] {n,m});
        visited[n][m] = true;

        while(!Q.isEmpty()){
            int A[] = Q.poll();
            for(int i=0; i<4; i++){
                int x = A[0] + dx[i];
                int y = A[1] + dy[i];
                if(x >= 0 && y >= 0 && x < N && y < M){
                    if(maze[x][y] != 0 && !visited[x][y]){
                        visited[x][y] = true;
                        maze[x][y] = maze[A[0]][A[1]] + 1;
                        Q.add(new int[] {x,y});
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.Search();
    }
}
