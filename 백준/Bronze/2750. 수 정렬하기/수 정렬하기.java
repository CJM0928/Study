import java.io.*;

public class Main {

    BufferedReader br;

    BufferedWriter bw;

    int N;

    int [] num;

    private void Bubblesort() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        num = new int[N];

        for(int i=0; i<N; i++){
            num[i] = Integer.parseInt(br.readLine());
        }

        for(int i=N-1; i>0; i--){
            for(int j=0; j<i; j++){
                if(num[j] > num[j+1]){
                    int temp = num[j];
                    num[j] = num[j+1];
                    num[j+1] = temp;
                }
            }
        }

        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i=0; i<N; i++){
            bw.write(num[i]+"\n");
        }
        bw.flush();
    }
    public static void main(String[] args)throws IOException{
        Main App = new Main();

        App.Bubblesort();
    }
}
