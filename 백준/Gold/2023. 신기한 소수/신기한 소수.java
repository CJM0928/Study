import java.io.*;

// 1자리 2자리 3자리 4자리 -> 1자리부터 소수여야함, 즉, 1자리가 소수인경우는 2,3,5,7 4개뿐

// 1번째 자리는 2,3,5,7 을 시작으로 둔다.

public class Main {
    
    BufferedReader br;

    
    int N;
    private void FindUtil() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        
        // 1의 자리부터 소수여야 하므로 2,3,5,7만 가능
        FindDFS(2,1);
        FindDFS(3,1);
        FindDFS(5,1);
        FindDFS(7,1);
    }

    private void FindDFS(int num, int len) throws IOException{
        if(len == N){
            System.out.println(num);
        }

        for(int i=1; i<=9; i++){
            if(i % 2 == 0){
                continue;
            }
            if(isPrime(num * 10 + i)){

                FindDFS(num * 10 + i,len+1);
            }
        }
    }

    private boolean isPrime(int num){
        for(int i=2; i*i <= num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();
        
        App.FindUtil();
    }
}
