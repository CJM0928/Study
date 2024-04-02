import java.util.Scanner;

public class Main {

    Scanner kb;

    int N;

    int [] Prime;
    private void FindMin(){
        kb = new Scanner(System.in);

        N = kb.nextInt();

        Prime = new int[10000001];

        for(int i=2; i<Prime.length; i++){
            Prime[i] = i;
        }

        for(int i=2; i<= Math.sqrt(Prime.length); i++){
            if(Prime[i] == 0){
                continue;
            }
            for(int j=i+i; j< Prime.length; j += i){
                Prime[j] = 0;
            }
        }

        for(int i=N; i<Prime.length; i++){
            if(Prime[i] == 0){
                continue;
            }
            String temp = String.valueOf(Prime[i]);
            String tmp = ""; // 여기에 1개씩 값을 옮겨준다
            for(int j=temp.length()-1; j>= 0; j--){
                tmp += String.valueOf(temp.charAt(j));
            }
            if(temp.equals(tmp)){
                System.out.println(Prime[i]);
                break;
            }
        }
    }


    public static void main(String[] args) {
        Main App = new Main();

        App.FindMin();
    }
}
