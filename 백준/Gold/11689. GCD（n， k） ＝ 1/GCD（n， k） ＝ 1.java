import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    BufferedReader br;

    long n;

    private void Start()throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));

        n = Long.parseLong(br.readLine());
        long answer = n;

        // 최대공약수 n으로 갱신하면서, n의 제곱근과 비교하여 배열을 진행
        for(long i=2; i<=Math.sqrt(n); i++){
            if(n % i == 0){
                answer -= answer/i;
                while (n % i == 0) {
                    n /= i;
                }
            }
        }

        if(n>1){
            answer -= answer/n;
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.Start();
    }
}
