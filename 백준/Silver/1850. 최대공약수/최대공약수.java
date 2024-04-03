import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Main {

    Scanner kb;

    long A;

    long B;

    BufferedWriter bw;

    private void find() throws IOException {
        kb = new Scanner(System.in);

        A = kb.nextLong();
        B = kb.nextLong();

        long len = gcd(A,B);

        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(long i=0; i<len; i++){
            bw.write("1");
        }
        kb.close();
        bw.flush();
    }

    private long gcd(long a, long b){
        if(b == 0){
            return a;
        }else{
            return gcd(b, a%b);
        }
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.find();
    }
}
