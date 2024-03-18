import java.io.*;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

// 해당 문제에서 최솟값 찾기를 for문으로
// Min = Integer.Max.Value 해서 찾게되면
// 시간초과가 발생.
// 따라서 Deque를 사용해서 삽입,삭제를 편하게 하자.

// 스캐너를 사용해서는 시간초과가 발생
// 이럴떄는 Buffer를 사용하는게 유리.

public class Main {
    class Node{
        int value;

        int index;

        Node(int value , int index){
            this.value = value;
            this.index = index;
        }
    }

    BufferedReader br;

    BufferedWriter bw;

    int N;

    int L;

    private void Find() throws IOException {
        // 딱봐도 입력
        br = new BufferedReader(new InputStreamReader(System.in));
        // 딱봐도 출력
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 예외처리 필요
        StringTokenizer st = new StringTokenizer(br.readLine());
        // N 과 L 을 먼저 담고
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        // 이제 각 val 담아준다.
        st = new StringTokenizer(br.readLine());
        Deque<Node> deque = new LinkedList<>();
        for(int i=0; i<N; i++){
            int val = Integer.parseInt(st.nextToken());        // 1 5 2 3 6 2 3 7 3 5 2 6

            while(!deque.isEmpty() && deque.getLast().value > val){ // 새로들어온 val 이 덱의 마지막 value보다 작다면,
                deque.removeLast();                                 // 마지막 value를 제거
            }
            deque.addLast(new Node(val,i));

            // i = 0 일때는 0,1,2 index 끼리만 비교 ( L 이 3이므로 )
            // i = 3 이 되면, index 1,2,3 끼리 비교
            if(deque.getFirst().index <= i - L){
                deque.removeFirst();
            }
            bw.write(deque.getFirst().value + " ");
        }
        br.close();
        bw.flush();
    }

    public static void main(String[] args) throws IOException{
        Main App = new Main();

        App.Find();
    }
}
