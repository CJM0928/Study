import java.util.Scanner;

public class Main {

    Scanner kb;

    int n,m;    // n : 도시 개수 , m : 여행 경로 데이터

    int[] parent;

    int[][] check;

    int[] route;    // 경로
    private void plan(){
        kb = new Scanner(System.in);

        n = kb.nextInt();
        m = kb.nextInt();

        parent = new int[n+1];
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }

        check = new int[n+1][n+1];

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                check[i][j] = kb.nextInt();
                if(check[i][j] == 1){
                    union(i,j);
                }
            }
        }

        route = new int[m+1];

        for(int i=1; i<=m; i++){
            route[i] = kb.nextInt();
        }

        int root_val = find(route[1]);

        for(int i=1; i<=m; i++){
            if(root_val != find(route[i])){
                System.out.println("NO");
                System.exit(0);
            }
        }

        System.out.println("YES");
    }

    private void union(int i, int j){
        i = find(parent[i]);
        j = find(parent[j]);

        if(i != j){
            parent[j] = i;
        }
    }

    private int find(int i){
        if(parent[i] == i){
            return i;
        }else{
            return parent[i] = find(parent[i]);
        }
    }

    public static void main(String[] args) {
        Main app = new Main();

        app.plan();
    }
}
