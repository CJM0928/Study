// 구간 합 구하기2
// N×N개의 수가 N×N 크기의 표에 채워져 있다. (x1, y1)부터 (x2, y2)까지 합을 구하는 프로그램을 작성하시오. (x, y)는 x행 y열을 의미한다.
// 예를 들어, N = 4이고, 표가 아래와 같이 채워져 있는 경우를 살펴보자.
// 여기서 (2, 2)부터 (3, 4)까지 합을 구하면 3+4+5+4+5+6 = 27이고, (4, 4)부터 (4, 4)까지 합을 구하면 7이다.
// 표에 채워져 있는 수와 합을 구하는 연산이 주어졌을 때, 이를 처리하는 프로그램을 작성하시오.

// 첫째 줄에 표의 크기 N과 합을 구해야 하는 횟수 M이 주어진다. (1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000)
// 둘째 줄부터 N개의 줄에는 표에 채워져 있는 수가 1행부터 차례대로 주어진다. 다음 M개의 줄에는 네 개의 정수 x1, y1, x2, y2 가 주어지며,
// (x1, y1)부터 (x2, y2)의 합을 구해 출력해야 한다. 표에 채워져 있는 수는 1,000보다 작거나 같은 자연수이다. (x1 ≤ x2, y1 ≤ y2)
import java.util.Scanner;

public class Main {

    Scanner kb;
    int [][] A;
    int [][] D;
    int N;

    int Q;
    private void sum(){
        kb =new Scanner(System.in);
        int N = kb.nextInt();
        int Q = kb.nextInt();
        A = new int[N+1][N+1];
        D = new int[N+1][N+1];

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                A[i][j] = kb.nextInt();
                D[i][j] = D[i-1][j] + D[i][j-1] - D[i-1][j-1] + A[i][j];
            }
        }

        for(int i=1; i<=Q; i++){
            int x1 = kb.nextInt();
            int y1 = kb.nextInt();
            int x2 = kb.nextInt();
            int y2 = kb.nextInt();
            System.out.println(D[x2][y2] - D[x1-1][y2] - D[x2][y1-1] + D[x1-1][y1-1]);
        }
    }

    public static void main(String[] args) {
        Main App = new Main();

        App.sum();
    }
}
