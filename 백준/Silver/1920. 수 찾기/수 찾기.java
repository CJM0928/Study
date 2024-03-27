import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    Scanner kb;

    int N,M;

    long [] Data;

    private void FindUtil(){
        kb = new Scanner(System.in);

        N = kb.nextInt();
        Data = new long[N];
        for(int i=0; i<N; i++){
            Data[i] = kb.nextInt();
        }
        Arrays.sort(Data);

        M = kb.nextInt();

        for(int i=0; i<M; i++){
            boolean find = false;
            int target = kb.nextInt();

            int start = 0;
            int end = N-1;
            while(start <= end){
                int middle = (start+end)/2;

                if(Data[middle] == target){
                    find = true;
                    break;
                }else if(Data[middle] > target){
                    end = middle - 1;
                }else{
                    start = middle + 1;
                }
            }

            if(find){
                System.out.println(1);
            }else{
                System.out.println(0);
            }
        }

        kb.close();
    }

    public static void main(String[] args){
        Main App = new Main();

        App.FindUtil();
    }
}
