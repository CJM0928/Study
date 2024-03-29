import java.util.*;

public class Main {

    Scanner kb;

    int N;

    int Sum;

    private void Sort(){
        kb = new Scanner(System.in);

        N = kb.nextInt();

        PriorityQueue<Integer> Q =  new PriorityQueue<Integer>();

        for(int i=0; i<N; i++){
            Q.add(kb.nextInt());
        }

        while(Q.size() != 1){
            int num1 = Q.poll();
            int num2 = Q.poll();
            int temp = num1 + num2;
            Sum += temp;
            Q.add(temp);
        }

        System.out.println(Sum);
    }

    public static void main(String[] args) {
        Main App = new Main();

        App.Sort();
    }
}
