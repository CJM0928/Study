import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    BufferedReader br;

    BufferedWriter bw;

    int N;

    int d = 5;      // 10000 보다 작거나 같은 자연수

    int idx = 1;

    int j = 1;

    int [] A;

    int [] B;

    int [] D;       // 1,10,100 자리 저장해주고, count 해줌
    private void Sort() throws IOException{

        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        A = new int[N];
        B = new int[N];
        D = new int[N];
        
        for(int i=0; i<N; i++){
            A[i] = Integer.parseInt(br.readLine());
        }

        while(d >= idx){
            D = new int[N];

            for(int i=0; i<N; i++){
                D[(A[i] / j) % 10]++;        // 여기가 핵심
            }
            for(int i=0; i<9; i++){
                D[i+1] += D[i];
            }
            for(int i=N-1; i>=0; i--){
                B[D[(A[i] / j) % 10]-1] = A[i];
                D[(A[i] / j) % 10]--;
            }
            for(int i=0; i<N; i++){
                A[i] = B[i];
            }
            idx++;
            j *= 10;
        }

        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i=0; i<N; i++){
            bw.write(A[i] + "\n");
        }

        bw.flush();
    }

    public static void main(String[] args)throws IOException {
        Main App = new Main();

        App.Sort();
    }
}
