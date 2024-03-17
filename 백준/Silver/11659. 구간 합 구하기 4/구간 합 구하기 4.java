// 구간 합 구하기
// 수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.
// 첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다.
// 둘째 줄에는 N개의 수가 주어진다. 수는 1,000보다 작거나 같은 자연수이다.
// 셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.

// 총 M개의 줄에 입력으로 주어진 i번째 수부터 j번째 수까지 합을 출력한다.
import java.util.Scanner;

public class Main {

    Scanner kb;

    int N,Q;
    int [] data;
    int [] S;
    int start,end;
    private void Sum(){
        kb = new Scanner(System.in);
        N = kb.nextInt();
        Q = kb.nextInt();
        data = new int[N+1];
        S = new int[N+1];

        for(int i=1; i<=N; i++){
            data[i] = kb.nextInt();
            S[i] = S[i-1] + data[i];
        }

        for(int i=1; i<=Q; i++){
            start = kb.nextInt();   // 시작
            end = kb.nextInt();     // 끝
            System.out.println(S[end]-S[start-1]);
        }
    }
    public static void main(String[] args) {
        Main App = new Main();

        App.Sum();
    }
}
