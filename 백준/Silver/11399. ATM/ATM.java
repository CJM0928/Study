import java.io.*;

public class Main {

    BufferedReader br;

    BufferedWriter bw;

    int N;

    int [] A;

    int Sum = 0;

    int tmp = 0;

    private void Calc() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        A = new int[N];

        String[] input = br.readLine().split(" ");
        for(int i=0; i<N; i++){
            int j = i-1;
            int temp = Integer.parseInt(input[i]);
            while(j >= 0) {
                if (A[j] > temp){
                    A[j+1] = A[j];
                    j--;
                }else{
                    break;
                }
            }
            A[j+1] = temp;
        }

        for(int i=0; i<N; i++){
            tmp += A[i];
            Sum += tmp;
        }

        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Sum + "");

        bw.flush();
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.Calc();
    }
}
