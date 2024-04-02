import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    BufferedReader br;

    int M,N;

    boolean [] Prime;

    private void Find() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        M = Integer.parseInt(input[0]);
        N = Integer.parseInt(input[1]);

        Prime = new boolean[N+1];
        
        for(int i=0; i<2; i++){
            Prime[i] = true;
        }

        for(int i=2; i<=Math.sqrt(N); i++){
            if(Prime[i]){
                continue;
            }
            for(int j=2; i*j <=N; j++){
                if(!Prime[i*j])
                    Prime[i*j] = true;  // i 인덱스를 제외한 나머지 배수들은 소수가 아님으로 처리
            }
        }

        for(int i=M; i<=N; i++){
            if(!Prime[i])
                System.out.println(i);
        }
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.Find();
    }
}
