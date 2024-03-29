import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;

public class Main {

    Scanner kb;

    int N,K;

    int [] Coin;

    int Sum,Count,idx;

    private void findMinimum() throws IOException{
        kb = new Scanner(System.in);

        N = kb.nextInt();
        K = kb.nextInt();

        Coin = new int[N];

        for(int i=0; i<N; i++){
            Coin[i] = kb.nextInt();
        }

        for(int i=N-1; i>=0; i--){
            if(Coin[i] <= K){        // !! 주의 !! K 가 1000인데 Coin[i] 가 1000이면 1개로 끝나는데 < 으로 해버리면 큰일남
                idx = i;
                break;
            }
        }

        for(int i=idx; i>=0; i--){
            if(K != 0){
                Count = K / Coin[i];
                K %= Coin[i];
                Sum += Count;
            }
            if (K == 0) {
                System.out.println(Sum);
                break;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.findMinimum();
    }
}
