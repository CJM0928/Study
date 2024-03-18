// 좋은 수
// N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를 “좋다(GOOD)”고 한다.
// N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라.
// 수의 위치가 다르면 값이 같아도 다른 수이다.

// 첫째 줄에는 수의 개수 N(1 ≤ N ≤ 2,000),
// 두 번째 줄에는 i번째 수를 나타내는 Ai가 N개 주어진다. (|Ai| ≤ 1,000,000,000, Ai는 정수)

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    Scanner kb;

    int Count;

    int N;

    int [] Num;

    private void FindGoodNumber(){
        kb = new Scanner(System.in);
        N = kb.nextInt();
        Num = new int[N];
        for(int i=0; i<N; i++){
            Num[i] = kb.nextInt();
        }

        Arrays.sort(Num);

        for(int k=0; k<N; k++){
            int Base = Num[k];
            int Start = 0;
            int End = N-1;

            while(Start < End){
                if(Num[Start] + Num[End] == Base){
                    if(Start != k && End != k){
                        Count++;
                        break;
                    }else if(Start == k){
                        Start++;
                    }else if(End == k){
                        End--;
                    }
                }else if(Num[Start] + Num[End] < Base){
                    Start++;
                }else{
                    End--;
                }
            }
        }

        System.out.println(Count);
    }

    public static void main(String[] args) {
        Main App = new Main();
        App.FindGoodNumber();
    }
}
