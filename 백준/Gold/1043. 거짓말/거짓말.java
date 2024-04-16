import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    Scanner kb;

    int n,m;

    int p;

    int k;

    int [] tp;

    int [] people;

    ArrayList<Integer>[] party;

    int cnt = 0;

    private void lier(){
        kb = new Scanner(System.in);

        n = kb.nextInt();
        m = kb.nextInt();

        p = kb.nextInt();

        if(p != 0){
            tp = new int[p];
            for(int i=0; i<p; i++){
                tp[i] = kb.nextInt();
            }
        }

        people = new int[n+1];

        for(int i=0; i<=n; i++){
            people[i] = i;
        }

        party = new ArrayList[m];
        for(int i=0; i<m; i++){
            party[i] = new ArrayList<Integer>();
            k = kb.nextInt();
            for(int j=0; j<k; j++){
                party[i].add(kb.nextInt());
            }
        }

        for(int i=0; i<m; i++){
            int fp = party[i].get(0);
            for(int j=1; j<party[i].size(); j++){
                union(fp,party[i].get(j));
            }
        }

        for(int i=0; i<m; i++){
            boolean lie = true;
            int pp = party[i].get(0);
            if(p != 0) {
                for (int j = 0; j < tp.length; j++) {
                    if (find(pp) == find(tp[j])) {
                        lie = false;
                        break;
                    }
                }
            }
            if(lie){
                cnt++;
            }
        }

        System.out.println(cnt);
    }

    private void union(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            people[b] = a;
        }
    }

    private int find(int a){
        if (people[a] == a){
            return a;
        }else{
            return people[a] = find(people[a]);
        }
    }

    public static void main(String[] args) {
        Main App = new Main();

        App.lier();
    }
}
