import java.io.*;

public class Main {

    BufferedReader br;

    BufferedWriter bw;

    int [] num;

    int N;

    int Max;

    String str;
    private void sort() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        str = br.readLine();
        N = str.length();

        num = new int[N];

        for(int i=0; i<N; i++){
            num[i] = Integer.parseInt(str.substring(i,i+1));
        }

        Max = Integer.MIN_VALUE;
        for(int i=0; i<N; i++){
            for(int j=i; j<N; j++){
                if(num[i] < num[j]){
                    int temp = num[j];
                    num[j] = num[i];
                    num[i] = temp;
                }
            }
        }
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i=0; i<N; i++){
            bw.write(num[i]+"");
        }

        bw.flush();
    }
    public static void main(String[] args)throws IOException {
        Main App = new Main();

        App.sort();
    }
}
