import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    BufferedReader br;

    StringTokenizer st;
    int [] A;

    boolean answer;
    private void Sequence() throws IOException {

        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        StringBuffer bf = new StringBuffer();   // +- 값들을 저장

        A = new int[N];

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            A[i] = Integer.parseInt(st.nextToken());
        }
        Stack<Integer> stack = new Stack<>();
        int num = 1;
        answer = true;

        for(int i=0; i<N; i++){
            int number = A[i];
            if(number >= num){
                while(number >= num){
                    stack.push(num++);
                    bf.append("+\n");
                }
                stack.pop();
                bf.append("-\n");
            }else{
                int n = stack.pop();
                //스택 가장 위의 숫자가 현재 pop 한 값보다 작다면 수열 출력에 문제가 생김
                if(n > number){
                    System.out.println("NO");
                    answer = false;
                    break;
                }else{
                    bf.append("-\n");
                }
            }
        }
        if(answer){
            System.out.println(bf.toString());
        }
        br.close();
    }
    public static void main(String[] args) throws IOException{
        Main App = new Main();

        App.Sequence();
    }
}
