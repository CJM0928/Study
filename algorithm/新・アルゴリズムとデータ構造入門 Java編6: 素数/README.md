# 소수 (Prime Number)

## 소수란
- **1보다 큰 자연수** 중에서, 양의 약수가 **1과 자기 자신만**인 수.

### 예시
- 소수  
  - 2, 3, 11, 41, 101
- 소수가 아님  
  - 1, 4, 16, 57, 100

---

## 간단한 소수 판정

### 판정 조건
정수 n 이 소수이다 ⇔  
- 정수 n 의 양의 약수가 **1과 n 뿐이다**  
- 즉, **2 이상 n 미만의 정수 중에서 n을 나누어떨어지게 하는 수가 존재하지 않는다**

---

## 포인트
- 소수 판정은 **“나누어떨어지는 수가 있는지 여부”**를 확인한다.  
- 실제 구현에서는 n 의 **제곱근까지만 확인**하면 충분하다.  
- 시험에서는 “소수의 정의”, “판정 조건”, “예시”를 확실히 이해하는 것이 중요하다.
  
---

## 예시코드

```
import java.util.Scanner;

public class Main {
    // n이 소수인지 판정하는 메서드
    public static boolean isPrime(int n) {
        if (n < 2) return false; // 1 이하의 수는 소수가 아님
        for (int i = 2; i * i <= n; i++) { // √n 까지만 확인
            if (n % i == 0) {
                return false; // 나누어떨어지면 소수가 아님
            }
        }
        return true; // 나누어떨어지는 수가 없으면 소수
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // 입력받은 정수

        if (isPrime(n)) {
            System.out.println(n + " は素数です。"); // 소수입니다
        } else {
            System.out.println(n + " は素数ではありません。"); // 소수가 아닙니다
        }
    }
}
```
