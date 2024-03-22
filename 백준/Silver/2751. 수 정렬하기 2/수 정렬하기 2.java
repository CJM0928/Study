import java.io.*;

public class Main {

    BufferedReader br;

    BufferedWriter bw;

    int N;

    int [] A;

    int [] temp;

    private void SortUtil() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        A = new int[N];
        temp = new int[N];

        for(int i=0; i<N; i++){
            A[i] = Integer.parseInt(br.readLine());
        }

        Sort(A,0,N-1);

        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i=0; i<N; i++){
            bw.write(A[i] + "\n");
        }

        bw.flush();
    }

    private void Sort(int []A, int start, int end){
        if(start < end){
            int middle = (start+end)/2;
            Sort(A,start,middle);
            Sort(A,middle+1,end);
            Merge(A,start,middle,end);
        }
    }

    private void Merge(int [] A, int start, int middle, int end){
        int idx = start;
        int S = start;
        int M = middle+1;

        while(S <= middle && M <= end){
            if(A[S] <= A[M]){
                temp[idx++] = A[S++];
            }else{
                temp[idx++] = A[M++];
            }
        }

        while(S <= middle){
            temp[idx++] = A[S++];
        }

        while(M <= end){
            temp[idx++] = A[M++];
        }

        for(int i=start; i<=end; i++){
            A[i] = temp[i];
        }
    }
    public static void main(String[] args) throws  IOException{
        Main App = new Main();

        App.SortUtil();
    }
}
