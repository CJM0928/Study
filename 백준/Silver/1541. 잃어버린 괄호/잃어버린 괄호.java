import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    BufferedReader br;

    String[] input;
    
    int answer = 0;
    private void Find() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));

        input = br.readLine().split("-");

        for(int i=0; i< input.length; i++){
            int sum = Sum(input[i]);
            
            // 만약 "-" 하나라도 존재한다면, split으로 쪼개지기때문에
            // i == 0이 아니라면 -가 존재한다는 의미
            if(i == 0){
                answer += sum;
            }else{
                answer -= sum;
            }
        }

        System.out.println(answer);
    }

    private int Sum(String num){
        int s = 0;
        String[] str = num.split("[+]");
        for(int i=0; i<str.length; i++){
            s += Integer.parseInt(str[i]);
        }
        return s;
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.Find();
    }
}
