import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    Scanner kb;

    int N;
    ArrayList<Input> list;

    class Input{
        int A;

        int B;

        Input(int a, int b){
            A = a;
            B = b;
        }

    }
    private void Find(){
        kb = new Scanner(System.in);
        N = kb.nextInt();
        list = new ArrayList<Input>(N);

        for(int i=0; i<N; i++){
            list = new ArrayList<>();
        }

        for(int i=0; i<N; i++){
            list.add(new Input(kb.nextInt(),kb.nextInt()));
        }

        for(int i=0; i<N; i++){
            int a = list.get(i).A;
            int b = list.get(i).B;

            while(a % b != 0){
                int c = a % b;
                a = b;
                b = c;
            }
            // a % b == 0 이라면 b는 최대공약수

            System.out.println(list.get(i).A * list.get(i).B / b);
        }
    }

    public static void main(String[] args) {
        Main App = new Main();

        App.Find();
    }
}
