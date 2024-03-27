import java.util.Scanner;

public class Main {

    Scanner kb;

    int N,M;

    int [] Lesson;

    int Sum;

    int cnt;
    int Start = 0;
    int End = 0;

    private void FindMin(){
        kb = new Scanner(System.in);

        int N = kb.nextInt();
        int M = kb.nextInt();

        Lesson = new int[N];

        for(int i=0; i<N; i++){
            Lesson[i] = kb.nextInt();
            if(Start < Lesson[i]){
                Start = Lesson[i];
            }
            End += Lesson[i];
        }

        while(Start <= End){
            int middle = (Start+End)/2;
            Sum = 0;
            cnt = 0;
            for(int i=0; i<N; i++){
                if(Sum + Lesson[i] > middle) {
                    cnt++;
                    Sum = 0;
                }
                Sum += Lesson[i];

            }
            if(Sum > 0){
                cnt++;
            }
            if(cnt > M){
                Start = middle+1;
            }else{              // cnt < M 이거나, cnt == M 이면 end 를 -1 할때마다 결국은 while 조건에 벗어남.
                End = middle-1;
            }
        }

        System.out.println(Start);


    }

    public static void main(String[] args) {
        Main App = new Main();

        App.FindMin();
    }
}
