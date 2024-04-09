import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    BufferedReader br;

    int [] send = {0,0,1,1,2,2};
    int [] resive = {1,2,0,2,0,1};

    boolean [][] visited;

    boolean [] answer;

    int [] num;
    class WaterInBottle{
        int A;
        int B;

        WaterInBottle(int A, int B){
            this.A = A;
            this.B = B;
        }
    }

    private void Sum() throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        num = new int[3];
        String[] input = br.readLine().split(" ");
        num[0] = Integer.parseInt(input[0]);
        num[1] = Integer.parseInt(input[1]);
        num[2] = Integer.parseInt(input[2]);
        
        visited = new boolean[201][201];    // A,B,C 는 200까지 이므로
        answer = new boolean[201];

        BFS();
        for(int i=0; i< answer.length; i++){
            if(answer[i]){
                System.out.print(i + " ");
            }
        }
    }

    private void BFS(){
        Queue<WaterInBottle> Q = new LinkedList<>();
        Q.add(new WaterInBottle(0,0));  // 시작은 물의양이 0,0
        visited[0][0] = true;
        answer[num[2]] = true;  // 맨 처음 C 의 양은 true

        while(!Q.isEmpty()){
            WaterInBottle value = Q.poll();
            int A = value.A;
            int B = value.B;
            int C = num[2] - A - B;
            for(int i=0; i<6; i++){
                int [] bottle = { A,B,C };
                bottle[resive[i]] += bottle[send[i]];   // send[i]에 있는 물을 resive[i] 한테 전달
                bottle[send[i]] = 0;                    // 보내줌으로써 send[i] 는 물이 사라짐
                if(bottle[resive[i]] > num[resive[i]]){ // 물을 받았더니 용량 초과일경우
                    bottle[send[i]] = bottle[resive[i]] - num[resive[i]];   // 물통에 받은값 - 최대용량 해서 기존 send[i] 물병에 다시 채움
                    bottle[resive[i]] = num[resive[i]]; // 따라서 받는 물병은 최대용량만큼만 가진다
                }

                if(!visited[bottle[0]][bottle[1]]){
                    visited[bottle[0]][bottle[1]] = true;
                    Q.add(new WaterInBottle(bottle[0],bottle[1]));
                    if(bottle[0] == 0){
                        answer[bottle[2]] = true;
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Main App = new Main();

        App.Sum();
    }
}
