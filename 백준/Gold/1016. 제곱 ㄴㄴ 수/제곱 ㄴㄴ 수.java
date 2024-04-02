import java.util.Scanner;

public class Main {

    Scanner kb;

    long Min,Max;

    long [] A;

    long Count;

    private void Find(){
        kb =new Scanner(System.in);

        Min = kb.nextLong();
        Max = kb.nextLong();

        A = new long[(int)(Max-Min+1)];     // 배열개수를 1000000 으로 줄일수있다!.

        for(int i=0; i<A.length; i++){
            A[i] = i+Min;
        }

        // start 지점을 만들어줘야하는데
        // Min 과 value가 나눠져서 0이 된다면, 
        // start 할때 -Min에 의해 인덱스 오류 발생

        for(long i=2; i*i<=Max; i++){
            long value = i*i;
            long start = Min / value;
            if(Min % value != 0){
                start++;
            }
            for(long j= start; value * j<=Max; j++){
                A[(int) ((value*j)-Min)] = 0;               // 처음에 Min을 + 해줬으니까.
            }
        }

        for(int i=0; i <= Max-Min; i++){
            if(A[i] != 0){
                Count++;
            }
        }

        System.out.println(Count);
    }

    public static void main(String[] args) {
        Main App = new Main();

        App.Find();
    }
}
