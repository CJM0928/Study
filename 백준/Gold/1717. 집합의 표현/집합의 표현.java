import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    BufferedReader br;

    int [] set;

    int n,m;

    String[] input;

    private void start() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));

        input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        set = new int[n+1];
        for(int i=0; i<=n; i++){
            set[i] = i;
        }

        for(int i=0; i<m; i++){
            input = br.readLine().split(" ");
            int q = Integer.parseInt(input[0]);
            int a = Integer.parseInt(input[1]);
            int b = Integer.parseInt(input[2]);

            if(q == 0){ // union
                union(a,b);
            }else{      // find
                boolean result = find(a,b);
                if(result){
                    System.out.println("YES");
                }else{
                    System.out.println("NO");
                }
            }
        }
    }

    private void union(int a, int b){
        a = findRoot(a);
        b = findRoot(b);

        if(a != b){
            set[b] = set[a];
        }
    }
    private boolean find(int a, int b){
        a = findRoot(a);
        b = findRoot(b);

        if(a == b){
            return true;
        }else{
            return false;
        }
    }

    private int findRoot(int a){
        if(set[a] != a) {
            set[a] = findRoot(set[a]);
        }
        return set[a];
    }

    public static void main(String[] args)throws IOException {
        Main app = new Main();

        app.start();
    }
}
