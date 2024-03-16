import java.util.Scanner;

// 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다.
// 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
// N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

public class Main {

    Scanner kb;

    int [] number;
    private void sort(){
        kb = new Scanner(System.in);
        int num = kb.nextInt();
        number = new int[num];

        for(int i=0; i<num; i++){
            number[i] = kb.nextInt();
        }

        for(int i=num-1; i>0; i--){
            for(int j=0; j<i; j++){
                if(number[j] > number[j+1]){
                    int temp = number[j];
                    number[j] = number[j+1];
                    number[j+1] = temp;
                }
            }
        }

        for(int i=0; i<num; i++){
            System.out.println(number[i]);
        }
        kb.close();
    }
    public static void main(String[] args) {
        Main App = new Main();

        App.sort();
    }
}
