# 최대공약수 / 최소공배수 (GCD / LCM)

## 1) 정의
- **최대공약수 (GCD)**: 모든 수에 공통으로 포함된 소인수의 **지수 중 최소값**을 곱한 것  
- **최소공배수 (LCM)**: 어떤 수에든 포함된 소인수의 **지수 중 최대값**을 곱한 것  

---

## 2) 소인수분해로 구하기 (예: 60, 75, 315)
- 60  = 2^2 × 3^1 × 5^1 × 7^0  
- 75  = 2^0 × 3^1 × 5^2 × 7^0  
- 315 = 2^0 × 3^2 × 5^1 × 7^1  

**GCD**: 각 소인수의 지수 중 **최소값(min)**  
→ 2^0 × 3^1 × 5^1 × 7^0 = **15**

**LCM**: 각 소인수의 지수 중 **최대값(max)**  
→ 2^2 × 3^2 × 5^2 × 7^1 = **6300**

---

## 3) 계산 팁 (시험 대비)
- 두 수 a, b 에 대해  
  **GCD(a, b) × LCM(a, b) = a × b**
- **유클리드 호제법** (GCD의 빠른 계산 방법)  
  - `gcd(a, b) = gcd(b, a mod b)`  
  - `gcd(x, 0) = x`  
- 세 수 이상일 때는 `gcd(a, b, c) = gcd(gcd(a, b), c)` 처럼 차례대로 계산  
  (LCM도 같은 방식)

---

## 4) 자주 하는 실수
- **1은 소수가 아니다** (하지만 GCD/LCM 결과에는 등장할 수 있음)  
- 지수 비교에서 **최소값(GCD)**, **최대값(LCM)** 을 헷갈리지 말 것  
- 여러 수의 LCM은 계산 중에 수가 커질 수 있으므로, **유클리드 호제법을 활용해서 순차적으로 계산**하는 것이 안전함  

---

## 5) 예제 확인
- 60, 75의 GCD:  
  60=2^2·3^1·5^1, 75=2^0·3^1·5^2  
  → 지수 최소값 = 2^0·3^1·5^1 = **15**

- 60, 75의 LCM:  
  → 지수 최대값 = 2^2·3^1·5^2 = **300**

- 검산:15 × 300 = 60 × 75
```
import java.util.Scanner;

public class Main {

    // 유클리드 호제법을 이용한 최대공약수
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return Math.abs(a); // 음수 입력 방지를 위해 절대값
    }

    // 최소공배수: a * b = gcd(a,b) * lcm(a,b) 공식 이용
    public static long lcm(int a, int b) {
        return (long) Math.abs((long) a / gcd(a, b) * b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("두 정수를 입력하세요: ");
        int a = sc.nextInt();
        int b = sc.nextInt();

        int g = gcd(a, b);
        long l = lcm(a, b);

        System.out.println("GCD = " + g);
        System.out.println("LCM = " + l);
    }
}
```

## 실행 예시
```
입력:60 75

출력:GCD = 15
    LCM = 300
```
