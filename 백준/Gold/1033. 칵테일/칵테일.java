// 예시 입력의 일부가 이해가 되질않아 코드를 치고나서 디버깅으로 이해한 문제
// 다음주에 다시 풀 것

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    
    ArrayList<Node> [] A;
    
    long lcm;
    
    boolean visited[];
    
    static long D[];

    Scanner kb;

    class Node{
        int b;
        int p;
        int q;

        Node(int b, int p, int q){
            super();
            this.b = b;
            this.p = p;
            this.q = q;
        }
    }

    private void find(){
        kb = new Scanner(System.in);

        int N =kb.nextInt();
        A = new ArrayList[N];
        visited = new boolean[N];
        D = new long[N];
        lcm = 1;

        for(int i=0; i<N; i++){
            A[i] = new ArrayList<Node>();
        }

        for(int i=0; i<N-1; i++){
            int a = kb.nextInt();
            int b = kb.nextInt();
            int p = kb.nextInt();
            int q = kb.nextInt();
            A[a].add(new Node(b,p,q));
            A[b].add(new Node(a,q,p));
            lcm *= (p * q / gcd(p,q));  // 최소 공배수는 두 수의 곱을 최대 공약수로 나뉜 것
        }

        D[0] = lcm;
        DFS(0);
        long mgcd = D[0];
        for(int i=1; i<N; i++){
            mgcd = gcd(mgcd,D[i]);
        }
        for(int i=0; i<N; i++){
            System.out.print(D[i] / mgcd + " ");
        }
    }

    private long gcd(long p, long q){
        if(q == 0){
            return p;
        }else{
            return gcd(q,p%q);
        }
    }

    private void DFS(int start){
        visited[start] = true;
        for(Node adjnode : A[start]) {
            int nextnode= adjnode.b;
            if(!visited[nextnode]){
                D[nextnode] = D[start] * adjnode.q / adjnode.p;
                DFS(nextnode);
            }
        }
    }

    public static void main(String[] args) {
        Main App = new Main();
        
        App.find();
    }
}
