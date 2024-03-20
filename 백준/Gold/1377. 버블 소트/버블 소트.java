import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    BufferedReader br;

    int N;

    array [] A;

    int Max;

    class array implements Comparable<array>{
        int value;

        int index;

        array(int value, int index){
            this.value = value;
            this.index = index;
        }

        @Override
        public int compareTo(array o) {
            return this.value - o.value;
        }
    }

    private void bubbleSortProgram() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        A = new array[N];
        for(int i=0; i<N; i++){
            A[i] =new array(Integer.parseInt(br.readLine()),i);
        }
        Arrays.sort(A);

        Max = Integer.MIN_VALUE;

        for(int i=0; i<N; i++){
            if(Max < A[i].index - i){
                Max = A[i].index - i;
            }
        }

        System.out.println(Max+1);
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.bubbleSortProgram();
    }

}
