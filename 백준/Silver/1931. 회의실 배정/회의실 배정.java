import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {

    BufferedReader br;

    int N;

    int [][] Meeting;

    int count = 0;

    int endTime = -1;

    private void MaxMeeting() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        Meeting = new int[N][2];

        String[] input;
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            Meeting[i][0] = Integer.parseInt(input[0]); // 시작
            Meeting[i][1] = Integer.parseInt(input[1]); // 끝
        }

        Arrays.sort(Meeting, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[1] == o2[1]) {
                    return o1[0] - o2[0];
                }
                return o1[1] - o2[1];
            }

        });

        for(int i=0; i<N; i++){
            if(endTime <= Meeting[i][0]){
                endTime = Meeting[i][1];
                count++;
            }
        }

        System.out.println(count);
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.MaxMeeting();
    }
}
