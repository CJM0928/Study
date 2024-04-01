// 여기서는 boolean 배열을 이용하는 방식을 하면 배열의 범위를 잡는게 어려워서 Long으로 하는게 나을듯

import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {

    Scanner kb;

    long N,M;

    long[] Prime;

    int count = 0;
    private void Find() throws IOException{
        kb = new Scanner(System.in);

        N = kb.nextLong();
        M = kb.nextLong();

        Prime = new long[10000001];

        for(int i=2; i< Prime.length; i++){
            Prime[i] = i;
        }

        for(int i=2; i<= Math.sqrt(Prime.length); i++){
            if(Prime[i] == 0){
                continue;
            }
            for(int j= i+i; j < Prime.length; j += i){
                Prime[j] = 0;
            }
        }

        for(int i=2; i< 10000001; i++){
            if(Prime[i] != 0){
                long temp = Prime[i];
                // 소수인 temp를 기준으로 제곱 시작
                while((double)Prime[i] <= (double) M /temp){
                    if((double)Prime[i] >= (double) N /temp){
                        count++;
                    }
                    temp *= Prime[i];
                }
            }
        }

        System.out.println(count);
    }
    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.Find();
    }
}
