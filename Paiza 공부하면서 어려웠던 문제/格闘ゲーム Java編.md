友達の家で N 人で遊んでいる paiza 君は格闘ゲームを遊ぶことにしました。
格闘ゲームのルールは次の通りです。

・ 各プレイヤーは 決まった hp と 3 種類の技を持っていて、技には強化系の技と攻撃の技があり、各攻撃技には技を出すための発生フレーム F とダメージ A が設定されている。

・ hp が 0 になったプレイヤーは退場となる。

・あるプレイヤー 1 が、他のプレイヤーにある技 T_1 (発生フレーム F_1 , 攻撃力 A_1) を使って攻撃した場合、攻撃を受けたプレイヤー 2 は反撃の技 T_2 (発生フレーム F_2 , 攻撃力 A_2) を選ぶ。その後、次のようなルールに従っていずれかのプレイヤーにダメージが入る。


どちらか片方でもプレイヤーが退場している場合、互いに何も起こらない。


強化系の技を使った場合、使ったプレイヤーの他の全ての技の発生フレーム（最短 1 フレーム) を -3 , 攻撃力を +5 する。
相手が攻撃技を使っていた場合、その攻撃の攻撃力分 hp が減少する。


互いに攻撃技を使った場合
・ F_1 < F_2 のとき、プレイヤー 2 の hp が A_1 減る
・ F_1 > F_2 のとき、プレイヤー 1 の hp が A_2 減る
・ F_1 = F_2 のとき、何も起こらない


各プレイヤーの持っている技についての情報と、技が出された回数、使われた技の詳細が与えられるので、全ての技が使われた後に場に残っているプレイヤーの人数を答えてください。

---

**入力される値**

```
N K
hp_1 F1_1 A1_1 F2_1 A2_1 F3_1 A3_1
...
hp_N F1_N A1_N F2_N A2_N F3_N A3_N
P1_1 T1_1 P2_1 T2_1
...
P1_K T1_K P2_K T2_K
```

・ 1 行目では、プレイヤー数 N と攻撃回数 K が与えられます。

・ 続く N 行のうち i 行目(1 ≦ i ≦ N)では、 i 番目のプレイヤーの hp である hp_i,
技 1 の発生フレーム F1_i , 攻撃力 A1_i
技 2 の発生フレーム F2_i , 攻撃力 A2_i
技 3 の発生フレーム F3_i , 攻撃力 A3_i が半角スペース区切りで与えられます。
ただし、発生フレーム・攻撃力が共に 0 である技は強化技であることを表しています。

・ 続く K 行のうち、 i 行目では i 回目の攻撃内容が与えられます。
技を使ったプレイヤーの番号 P1_i と P1_i が選んだ技の番号 T1_i
技を使ったプレイヤーの番号 P2_i と P2_i が選んだ技の番号 T2_i
が半角スペース区切りで与えられます。

入力値最終行の末尾に改行が１つ入ります。
文字列は標準入力から渡されます。

---

**期待する出力**

場に残っているプレイヤーの人数を 1 行で出力してください。

---

**条件**

・ 1 ≦ N , K ≦ 1000
・ 1 ≦ hp_i ≦ 100 (1 ≦ i ≦ N)
・ 0 ≦ F1_i , F2_i , F3_i ≦ 60 (1 ≦ i ≦ N)
・ 0 ≦ A1_i , A2_i , A3_i ≦ 30 (1 ≦ i ≦ N)
・ 1 ≦ P1_i , P2_i ≦ N , P1_i ≠ P2_i　(1 ≦ i ≦ K)
・ T1_i , T2_i は 1 , 2 , 3 のいずれか (1 ≦ i ≦ K)
・ 強化技は各プレイヤーに最大 1 つまで

---

入力例1
```
3 6
10 1 1 2 2 3 3
10 0 0 6 1 7 2
10 0 0 7 5 8 3
1 1 2 2
1 2 3 2
1 3 2 3
2 2 3 1
2 3 3 1
1 2 3 2
```

---

出力例1
```
2
```

---

入力例2
```
5 10
8 2 24 40 25 42 26
59 48 13 21 13 56 2
5 59 7 57 5 25 24
99 28 6 32 5 23 2
62 24 19 11 19 7 21
2 1 3 2
2 1 3 2
5 1 3 1
5 3 1 2
1 1 2 2
4 2 3 1
5 3 3 2
2 3 3 2
4 1 5 3
2 3 3 2
```

---

出力例2
```
3
```

---

```

import java.util.*;

class Player{
    int hp;
    
    int[] a = new int[3];
    int[] f = new int[3];
    
    boolean state = false;
    int buffIdx  = -1;
    
    Player(int hp, int f1, int a1, int f2, int a2, int f3, int a3){
        this.hp = hp;
        
        f[0] = f1;
        a[0] = a1;
        f[1] = f2;
        a[1] = a2;
        f[2] = f3;
        a[2] = a3;
        
        for(int i=0; i<3; i++){
            if(f[i] == 0 && a[i] == 0){
                buffIdx = i;
                break;
            }
        }
    }
    
    public Map<Integer,Integer> useSkill(int skillNum){
        int index = skillNum - 1;
        
        if(index == buffIdx){
            applyBuff();
            return null;
        }
        
        Map<Integer, Integer> use = new HashMap<>();
        
        use.put(f[index],a[index]);
        return use;
    }
    
    public void applyBuff(){
        for(int i = 0; i<3; i++){
            if(i == buffIdx){
                continue;
            } else{
                f[i] = Math.max(1,f[i] -3);
                a[i] += 5;
            }
        }
    }
    
    public void attacked(int damage){
        hp -= damage;
        if(hp <= 0){
            state = true;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // 自分の得意な言語で
        // Let's チャレンジ！！
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        ArrayList<Player> arr = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            arr.add(new Player(sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt()));    
        }
        
        for(int i=0; i<k; i++){
            int p1 = sc.nextInt() - 1;
            int mp1 = sc.nextInt();
            int p2 = sc.nextInt() - 1;
            int mp2 = sc.nextInt();
            
            Player a = arr.get(p1);
            Player b = arr.get(p2);
            
            if(a.state || b.state){
                continue;
            }
            
            Map<Integer,Integer> temp1 = a.useSkill(mp1);
            Map<Integer,Integer> temp2 = b.useSkill(mp2);
            
            
            int adjMp1 = -1;
            int dmg1   = 0;
            int adjMp2 = -1;
            int dmg2   = 0;
            
            if(temp1 != null && !temp1.isEmpty()){
                Map.Entry<Integer,Integer> e1 = temp1.entrySet().iterator().next();    
                adjMp1 = e1.getKey();
                dmg1   = e1.getValue();
            }
            
            if(temp2 != null && !temp2.isEmpty()){
                Map.Entry<Integer,Integer> e2 = temp2.entrySet().iterator().next();
                adjMp2 = e2.getKey();
                dmg2   = e2.getValue();
            }
            
            if (temp1 == null && temp2 == null) {
                continue;
            } else if (temp1 == null) {
                a.attacked(dmg2);
                continue;
            } else if (temp2 == null) {
                b.attacked(dmg1);
                continue;
            }

            if(adjMp1 == adjMp2){
                continue;
            } else if(adjMp1 > adjMp2){
                a.attacked(dmg2);
            } else if(adjMp1 < adjMp2){
                b.attacked(dmg1);
            }

        }
        
        int count = 0;
        
        for(Player player : arr){
            if(!player.state){
                count++;
            }
        }
        
        System.out.println(count);
    }
}
```

---

**답안지**

```
import java.util.Scanner;

class Player {

    int hp;
    int[] f, a;

    Player(int hp, int f1, int a1, int f2, int a2, int f3, int a3) {
        this.hp = hp;
        this.f = new int[] { f1, f2, f3 };
        this.a = new int[] { a1, a2, a3 };
    }

    void enhance() {
        for (int i = 0; i < 3; i++) {
            if (a[i] == 0 && f[i] == 0) {
                continue;
            }

            a[i] += 5;
            f[i] = Math.max(f[i] - 3, 1);
        }
    }

    boolean isAlive() {
        return hp > 0;
    }

    void takeDamage(int d) {
        hp -= d;
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        Player[] players = new Player[n];
        for (int i = 0; i < n; i++) {
            int hp = sc.nextInt();
            int f1 = sc.nextInt();
            int a1 = sc.nextInt();
            int f2 = sc.nextInt();
            int a2 = sc.nextInt();
            int f3 = sc.nextInt();
            int a3 = sc.nextInt();
            players[i] = new Player(hp, f1, a1, f2, a2, f3, a3);
        }

        for (int i = 0; i < k; i++) {
            int p1Index = sc.nextInt() - 1;
            int t1 = sc.nextInt() - 1;
            int p2Index = sc.nextInt() - 1;
            int t2 = sc.nextInt() - 1;

            Player p1 = players[p1Index];
            Player p2 = players[p2Index];

            if (!p1.isAlive() || !p2.isAlive()) {
                continue;
            }

            int f1 = p1.f[t1];
            int a1 = p1.a[t1];
            int f2 = p2.f[t2];
            int a2 = p2.a[t2];
            boolean p1Enhance = a1 == 0 && f1 == 0;
            boolean p2Enhance = a2 == 0 && f2 == 0;

            if (p1Enhance && p2Enhance) {
                p1.enhance();
                p2.enhance();
            } else if (p1Enhance) {
                p1.enhance();
                p1.takeDamage(a2);
            } else if (p2Enhance) {
                p2.takeDamage(a1);
                p2.enhance();
            } else {
                if (f1 < f2) {
                    p2.takeDamage(a1);
                } else if (f1 > f2) {
                    p1.takeDamage(a2);
                }
            }
        }

        int numOfAlivePlayers = 0;
        for (Player player : players) {
            if (player.isAlive()) {
                numOfAlivePlayers++;
            }
        }

        System.out.println(numOfAlivePlayers);
    }
}
```

---

**다른방법**

```
import java.util.*;

class AttackResult {
    final boolean isAttack; // true: 공격, false: 강화
    final int frame;        // isAttack=true일 때만 의미
    final int damage;       // isAttack=true일 때만 의미
    AttackResult(boolean isAttack, int frame, int damage) {
        this.isAttack = isAttack;
        this.frame = frame;
        this.damage = damage;
    }
    static AttackResult buff() { return new AttackResult(false, 0, 0); }
    static AttackResult attack(int f, int a) { return new AttackResult(true, f, a); }
}

class Player{
    int hp;
    int[] a = new int[3];
    int[] f = new int[3];
    boolean state = false;
    int buffIdx  = -1;

    Player(int hp, int f1, int a1, int f2, int a2, int f3, int a3){
        this.hp = hp;
        f[0]=f1; a[0]=a1;
        f[1]=f2; a[1]=a2;
        f[2]=f3; a[2]=a3;
        for(int i=0;i<3;i++){
            if(f[i]==0 && a[i]==0){ buffIdx=i; break; }
        }
    }

    // 기술 번호(1~3)
    AttackResult useSkill(int skillNum){
        int idx = skillNum - 1;
        if (idx == buffIdx){ // 강화
            applyBuff();
            return AttackResult.buff();
        }
        return AttackResult.attack(f[idx], a[idx]); // 현재 누적 수치로 공격
    }

    void applyBuff(){
        for(int i=0;i<3;i++){
            if(i==buffIdx) continue;
            f[i] = Math.max(1, f[i]-3);
            a[i] += 5;
        }
    }

    void attacked(int damage){
        hp -= damage;
        if(hp <= 0) state = true;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();

        ArrayList<Player> arr = new ArrayList<>();
        for(int i=0;i<n;i++){
            arr.add(new Player(
                sc.nextInt(), sc.nextInt(), sc.nextInt(),
                sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt()
            ));
        }

        for(int i=0;i<k;i++){
            int p1 = sc.nextInt()-1, t1 = sc.nextInt();
            int p2 = sc.nextInt()-1, t2 = sc.nextInt();

            Player A = arr.get(p1), B = arr.get(p2);
            if (A.state || B.state) continue;

            AttackResult r1 = A.useSkill(t1);
            AttackResult r2 = B.useSkill(t2);

            // 둘 다 강화
            if (!r1.isAttack && !r2.isAttack) continue;

            // 한쪽만 공격
            if (!r1.isAttack && r2.isAttack) { A.attacked(r2.damage); continue; }
            if ( r1.isAttack && !r2.isAttack) { B.attacked(r1.damage); continue; }

            // 둘 다 공격 → 프레임 비교
            if (r1.frame == r2.frame) continue;
            if (r1.frame < r2.frame) B.attacked(r1.damage);
            else A.attacked(r2.damage);
        }

        int alive = 0;
        for (Player p : arr) if (!p.state) alive++;
        System.out.println(alive);
    }
}
```

