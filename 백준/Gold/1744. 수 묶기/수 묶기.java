import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    Scanner kb;

    int N;

    int idx1,idx2;  //

    int sum;
    int Bsum,Csum;

    int [] A;

    int [] B;

    int [] C;

    private void MakeMax(){
        kb = new Scanner(System.in);

        N = kb.nextInt();

        A = new int[N];

        for(int i=0; i<N; i++){
            A[i] = kb.nextInt();
            if(A[i] <= 0){
                idx1++;
            }else{
                idx2++;
            }
        }

        B = new int[idx1];
        C = new int[idx2];

        idx1 = 0;
        idx2 = 0;
        Arrays.sort(A);

        for(int i=0; i<N; i++){
            if(A[i] <= 0){
                B[idx1++] = A[i];
            }else{
                C[idx2++] = A[i];
            }
        }

        for(int i=0; i<B.length; i = i+2){
            if(i+1 >= B.length){
                Bsum += B[i];
            }else {
                sum = B[i] * B[i + 1];
                Bsum += sum;
            }
        }

        for(int i=C.length-1; i>=0; i = i-2){
            if(i-1 < 0){
                Csum += C[i];
            }else{
                if(C[i] * C[i-1] > C[i] + C[i-1]) {
                    sum = C[i] * C[i - 1];
                    Csum += sum;
                }else{
                    sum = C[i] + C[i - 1];
                    Csum += sum;
                }
            }
        }

        System.out.println(Bsum + Csum);
    }

    public static void main(String[] args) {

        Main App = new Main();

        App.MakeMax();
    }
}
