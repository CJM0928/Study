## Grundy 수 계산 문제 (mex 및 XOR 응용)

### 그란디 수 정의

```
・ grundy(0) = grundy(1) = 0
・ grundy(x) = mex({ grundy(i) xor grundy(x - i - 2) | i = 0, 1, 2, ..., x - 2 })
```

---

- 여기서 mex(S)는 집합 S에 포함되지 않은 가장 작은 비음수 정수를 의미
- 예를 들어, S = {0, 1, 3}이면 mex(S) = 2

---

## 1. Grundy 수란?

- 각 상태 x에서의 승패 상태를 숫자로 표현한 값.
- 0이면 지는 상태, 0이 아니면 이기는 상태입니다.

## 2. 그란디 수의 작동순서
  1. `grundy(x)`를 구하기 위해
  2. 현재 상태 x에서 이동 가능한 모든 다음 상태의 Grundy값을 XOR한 결과 집합을 만든다.
  3. 그 집합에 포함되지 않은 가장 작은 정수를 찾는다.
  4. 그것이 바로 `grundy(x)` 값

## 3. mex 함수란?
- mex(S) = “집합 S에 포함되지 않은 가장 작은 비음수 정수”
  
| S       | mex(S) |
| :------ | :----- |
| `{}`    | 0      |
| `{0}`   | 1      |
| `{0,1}` | 2      |
| `{1,2}` | 0      |
| `{0,2}` | 1      |

→ 즉, **while문으로 0부터 차례로 검사하다가 처음 빠진 숫자가 mex**

```
package test.test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Test24 {

    // mex 함수: 집합에 포함되지 않은 가장 작은 정수를 반환
    public static int mex(Set<Integer> s) {
        int g = 0;
        while (s.contains(g)) g++;
        return g;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());

        int[] dp = new int[Math.max(n + 1, 2)];
        dp[0] = 0;
        dp[1] = 0;

        for (int x = 2; x <= n; x++) {
            Set<Integer> set = new HashSet<>(); // 매 단계마다 새로 생성 (clear 대체)
            for (int i = 0; i <= x - 2; i++) {
                set.add(dp[i] ^ dp[x - i - 2]);
            }
            dp[x] = mex(set);
        }

        System.out.println(dp[n]);
    }
}
```

