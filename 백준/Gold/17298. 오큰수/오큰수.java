// 오큰수
// 크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다.
// Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.

// 예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. A = [9, 5, 4, 8]인 경우에는
// NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
// 둘째 줄에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

// 총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.
public class Main {
    BufferedReader br;

    int [] A;

    int [] answer;

    int N;

    Stack<Integer> stack;
    private void nge() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        A = new int[N];
        answer = new int[N];

        String[] input = br.readLine().split(" ");  // 3 2 5 7 을 받으면 " " 기준으로 input에 값을 넣어줌.
        for(int i=0; i<N; i++){
            A[i] = Integer.parseInt(input[i]);
        }
        
        stack = new Stack<>();
        // 인덱스 기준으로 풀어 나가기
        stack.push(0);

        for(int i=1; i<N; i++){
            while(!stack.isEmpty() && A[stack.peek()] < A[i]){
                answer[stack.pop()] = A[i];
            }
            stack.push(i);
        }
        while(!stack.isEmpty()){
            answer[stack.pop()] = -1;
        }

        BufferedWriter br = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i=0; i<N; i++){
            br.write(answer[i] +" ");
        }
        br.write("\n");
        br.flush();
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.nge();
    }
}
