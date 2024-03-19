import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    BufferedReader br;

    int N;  // 카드 개수

    Queue<Integer> Q;


    private void cardgame() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        Q = new LinkedList<>();

        int idx = 1;        // 뽑는횟수
        int val = 0;        // 뽑아서 나온 값

        for(int i=1; i<=N; i++){
            Q.add(i);
        }

        while(!Q.isEmpty()){
            if(idx % 2 == 1){
                val = Q.poll();
            }else{
                val = Q.poll();
                Q.add(val);
            }
            idx++;
        }

        System.out.println(val);
    }

    public static void main(String[] args) throws IOException{
        Main App = new Main();

        App.cardgame();
    }
}
