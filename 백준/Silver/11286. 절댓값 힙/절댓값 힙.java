import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {

    BufferedReader br;
    int N;
    PriorityQueue<Integer> Queue;

    private void Heap() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringBuffer bf = new StringBuffer();

        // 우선순위 큐 정렬 하는 방식.
        // add할때도 우선순위큐는 정렬을하고,
        // poll 할때도 우선순위큐는 정렬을하고
        // 메서드를 호출할때마다 필요한 기능을 수행한다고 봐도 된다.
        
        Queue = new PriorityQueue<>((o1,o2) -> {
           int firstABS = Math.abs(o1);
           int secondABS = Math.abs(o2);
            if (firstABS == secondABS) {
                return o1 > o2 ? 1 : -1;
            }else{
                return firstABS-secondABS;
            }
        });

        for(int i=0; i<N; i++){
            int Value = Integer.parseInt(br.readLine());
            if(Value == 0){
                if(Queue.isEmpty()){
                    System.out.println(0);
                }else{
                    System.out.println(Queue.poll());
                }
            }else{
                Queue.add(Value);
            }
        }
    }
    public static void main(String[] args) throws IOException{
        Main App = new Main();

        App.Heap();
    }
}
