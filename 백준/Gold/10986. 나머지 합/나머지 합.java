import java.util.Scanner;

public class Main {

    Scanner kb;

    long[] A;

    long[] B;

    long[] remainder;

    long answer = 0;

    private void Remainder(){
        kb = new Scanner(System.in);

        int N = kb.nextInt();
        int M = kb.nextInt();

        A = new long[N+1];
        B = new long[N+1];

        remainder = new long[M];

        for(int i=1; i<=N; i++){
            A[i] = kb.nextLong();
            B[i] = B[i-1] + A[i];

            int result =(int)(B[i] % M);
            if(result == 0){
                answer++;
            }
            remainder[result]++;
        }

        for(int i=0; i<M; i++){
            if(remainder[i] > 0)
                answer += ((remainder[i] * (remainder[i]-1))/2);
        }

        System.out.println(answer);
    }

    public static void main(String[] args) {
        Main App = new Main();

        App.Remainder();
    }
}
