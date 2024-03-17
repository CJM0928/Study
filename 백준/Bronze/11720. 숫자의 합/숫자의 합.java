import java.util.Scanner;

// 숫자의 합 구하기
// N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.
// 첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.
// 입력으로 주어진 숫자 N개의 합을 출력한다.
public class Main {

    Scanner kb;

    private void sum(){

        kb = new Scanner(System.in);
        int N = kb.nextInt();
        String sNum = kb.next();
        char [] chars = new char[N];

        int result = 0;

        for(int i=0; i<N; i++){
            chars[i] = sNum.charAt(i);
        }

        for(int i=0; i<N; i++){
            result += chars[i] -48;
        }

        System.out.println(result);
    }
    public static void main(String[] args) {
        Main App = new Main();
        App.sum();

    }
}
