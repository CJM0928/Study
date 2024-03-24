import java.io.*;
import java.util.StringTokenizer;

public class Main {

    BufferedReader br;

    BufferedWriter bw;

    long idx = 0;

    int N;

    int [] A;

    int [] temp;

    private void start() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        A = new int[N+1];
        temp = new int[N+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=1; i<=N; i++){
            A[i] = Integer.parseInt(st.nextToken());
        }

        Sort(1,N);

        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(idx + " ");

        bw.flush();
    }

    private void Sort(int start, int end){
        if(end - start < 1)
            return;

        int middle = start + (end - start) / 2;
        Sort(start,middle);
        Sort(middle+1,end);

        for(int i=start; i<=end; i++){
            temp[i] = A[i];
        }

        int index = start;
        int S = start;
        int M = middle+1;

        while(S <= middle && M <= end){
            if(temp[S] > temp[M]){
                A[index++] = temp[M++];
                idx += (middle - S + 1);
            }else{
                A[index++] = temp[S++];
            }
        }

        while(S <= middle){
            A[index++] = temp[S++];
        }

        while(M <= end){
            A[index++] = temp[M++];
        }

    }



    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.start();

    }
}
