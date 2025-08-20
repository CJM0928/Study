# 병렬 이진 탐색 (Parallel Binary Search) – Java 예제

여러 쿼리 각각에 대해 “시간 `t`에 대한 판정(예: `F(t) ≥ X`)”으로 이진 탐색을 해야 할 때,  
각 쿼리를 따로 `log T`번 평가하지 않고 **한 라운드에서 모든 쿼리의 mid를 같이 처리**하는 틀입니다.

## 핵심 아이디어
- 각 쿼리 j의 정답은 `[0, T]` 범위에 존재한다고 가정한다.  
- 모든 쿼리에 대해 `(lo[j], hi[j])`를 유지하고, `mid[j] = (lo[j] + hi[j]) / 2`를 **동시에** 잡는다.
- `mid`가 같은 쿼리들을 **버킷(그룹)** 으로 묶고, 그 `mid`에서의 판정 결과로 구간을 절반으로 줄인다.
- 이를 구간이 수렴할 때까지 반복한다. (대개 `log T` 라운드)

> ⚠️ 최적화 포인트: 한 라운드에서 `mid`들을 오름차순으로 처리하며 시뮬레이션 상태를 누적(sweep)할 수 있으면  
> `f(t)` 재계산을 크게 줄일 수 있다. (문제 성질에 따라 가능/불가능)

---

## 예제 시나리오
- `machines = [ti]` (각 기계의 생산 주기)  
- `F(t) = Σ floor(t / ti)`  
- 질의 `X = [x1, x2, ...]` 에 대해 `F(t) ≥ Xj` 를 처음 만족하는 최소 `t`를 모두 구한다.

---

## 코드 1) 병렬 이진 탐색 틀 + 생산 문제

```java
import java.util.*;
import java.util.function.LongUnaryOperator;

public class Main {

    // F(t): 시간 t까지 총 생산량 (단조 증가)
    static long producedUntil(long t, long[] machines) {
        long sum = 0;
        for (long ti : machines) {
            sum += t / ti; // floor(t / ti)
            if (sum < 0) return Long.MAX_VALUE; // overflow 가드(실전용)
        }
        return sum;
    }

    /**
     * 병렬 이진 탐색 (Parallel Binary Search)
     *
     * @param targets Xj 배열 (각 쿼리의 목표값)
     * @param T       탐색 상한 (정답이 [0, T] 안에 있다고 가정)
     * @param f       단조증가 함수 f(t) (예: producedUntil(t))
     * @return        각 쿼리 j에 대한 최소 t (f(t) >= targets[j]) 
     */
    static long[] parallelBinarySearch(long[] targets, long T, LongUnaryOperator f) {
        int Q = targets.length;
        long[] lo = new long[Q];
        long[] hi = new long[Q];
        Arrays.fill(lo, 0L);
        Arrays.fill(hi, T);

        // 아직 수렴하지 않은 인덱스가 있는 동안 반복
        while (true) {
            // mid -> 해당 mid를 조사해야 하는 쿼리 인덱스들
            Map<Long, List<Integer>> bucket = new HashMap<>();
            boolean any = false;

            for (int i = 0; i < Q; i++) {
                if (lo[i] < hi[i]) {
                    any = true;
                    long mid = (lo[i] + hi[i]) >>> 1; // 무부호 쉬프트로 overflow 안전
                    bucket.computeIfAbsent(mid, k -> new ArrayList<>()).add(i);
                }
            }
            if (!any) break; // 모든 쿼리가 수렴

            // (선택) mid를 정렬해 오름차순으로 처리하면, 
            // 문제 성질에 따라 f를 누적 계산(sweep)으로 최적화 가능
            List<Long> mids = new ArrayList<>(bucket.keySet());
            Collections.sort(mids);

            for (long mid : mids) {
                long val = f.applyAsLong(mid); // f(mid) 평가 (여기선 독립 호출)

                for (int idx : bucket.get(mid)) {
                    if (val >= targets[idx]) {
                        hi[idx] = mid;
                    } else {
                        lo[idx] = mid + 1;
                    }
                }
            }
        }
        // 수렴 시점: lo[i] == hi[i]
        return lo;
    }

    public static void main(String[] args) {
        // 예시 입력 (하드코딩): 기계 3대, 질의 3개
        long[] machines = {2, 3, 7};      // 각 기계의 생산 주기(초)
        long[] queries  = {5, 10, 20};    // 목표 생산량 Xj
        long T = 1_000_000_000L;          // 충분히 큰 상한

        // f(t) 람다: producedUntil(t, machines)
        LongUnaryOperator f = t -> producedUntil(t, machines);

        long[] ans = parallelBinarySearch(queries, T, f);

        System.out.println("최소 시각들: " + Arrays.toString(ans));
        // 검증 출력
        for (int i = 0; i < queries.length; i++) {
            long t = ans[i];
            long val = producedUntil(t, machines);
            System.out.printf("X=%d -> t=%d (F(t)=%d)%n", queries[i], t, val);
            if (t > 0) {
                long valPrev = producedUntil(t - 1, machines);
                assert valPrev < queries[i] && val >= queries[i];
            }
        }
    }
}
