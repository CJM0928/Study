import java.util.Scanner;

// 배열처럼 보이지만
// 배열로 접근하면 안되는 문제.
public class Main {

    int N;

    int K;

    Scanner kb;

    int answer;

    private void Find(){
        kb = new Scanner(System.in);
        N = kb.nextInt();
        K = kb.nextInt();

        int start = 1;
        int end = K;

        while(start <= end){
            int middle = (start+end)/2;

            int Sum = 0;
            for(int i=1; i<=N; i++){
                Sum += Math.min(middle/i,N);        // 이부븐을 전혀 몰랐어가지고, 해답을 참고했음
            }

            if(Sum < K){
                start = middle+1;
            }else{
                // 시간복잡도 해결하기 위한 방법
                answer = middle;
                end = middle-1;
            }
        }

        System.out.println(answer);
    }

    public static void main(String[] args) {
        Main App = new Main();

        App.Find();
    }
}
