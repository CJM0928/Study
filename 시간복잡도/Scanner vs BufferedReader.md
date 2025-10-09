## 1. 개요

| 항목           | **Scanner**                            | **BufferedReader**                                                          |
| ------------ | -------------------------------------- | --------------------------------------------------------------------------- |
| **기본 패키지**   | `java.util`                            | `java.io`                                                                   |
| **입력 단위**    | 토큰(공백·개행 자동 분리)                        | 줄 단위(`readLine()`)                                                          |
| **속도**       | 느림 (정규식 기반)                            | 빠름 (버퍼 기반)                                                                  |
| **형 변환**     | 자동 (`nextInt()`, `nextDouble()`)       | 수동 (`Integer.parseInt()`)                                                   |
| **예외 처리**    | 필요 없음                                  | `throws IOException` 필요                                                     |
| **적합한 상황**   | 입력이 적고, 간단한 문제                         | 입력이 많거나, 속도 중요한 문제                                                          |
| **기본 사용 예시** | `Scanner sc = new Scanner(System.in);` | `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));` |

--- 

## 2. 주요 메서드 대응표

| **Scanner 메서드** | **BufferedReader 대체 방식**                | **설명**           |
| --------------- | --------------------------------------- | ---------------- |
| `next()`        | `new StringTokenizer(line).nextToken()` | 공백 기준으로 단어 하나 읽기 |
| `nextInt()`     | `Integer.parseInt(st.nextToken())`      | 정수 하나 읽기         |
| `nextDouble()`  | `Double.parseDouble(st.nextToken())`    | 실수 하나 읽기         |
| `nextLine()`    | `br.readLine()`                         | 한 줄 전체 읽기        |
| `hasNext()`     | `(line = br.readLine()) != null`        | 입력이 남았는지 확인      |
| `close()`       | `br.close()`                            | 스트림 닫기           |
| `nextLong()`    | `Long.parseLong(st.nextToken())`        | 긴 정수 읽기          |
| `nextBoolean()` | `Boolean.parseBoolean(st.nextToken())`  | 불리언 값 읽기         |

--- 

## 3. BufferedReader + StringTokenizer 템플릿

```
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // BufferedReader로 빠른 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 1️⃣ 첫 줄 입력 → 공백으로 구분된 정수 2개
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); // 예: 배열 크기
        int k = Integer.parseInt(st.nextToken()); // 예: 더할 값

        // 2️⃣ 두 번째 줄 입력 → N개의 정수
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        // 3️⃣ 로직 처리 (예: 각 원소에 k를 더하기)
        StringBuilder sb = new StringBuilder();
        for (int x : arr) {
            sb.append(x + k).append("\n");
        }

        // 4️⃣ 출력
        System.out.print(sb.toString());

        br.close(); // 자원 정리
    }
}

```
### 입력 예시
```
5 3
1 2 3 4 5
```

### 출력 예시
```
4
5
6
7
8
```

---

## 4.설명
| 단계                       | 코드                                                                          | 설명                      |
| ------------------------ | --------------------------------------------------------------------------- | ----------------------- |
| **1. BufferedReader 선언** | `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));` | 표준 입력을 버퍼로 읽어서 빠른 속도 확보 |
| **2. 한 줄 읽기**            | `br.readLine()`                                                             | 한 줄 전체를 문자열로 읽기         |
| **3. 문자열 분리**            | `new StringTokenizer(line)`                                                 | 공백 단위로 나누기 (split보다 빠름) |
| **4. 토큰 추출**             | `st.nextToken()`                                                            | 공백 기준으로 하나씩 꺼내기         |
| **5. 형 변환**              | `Integer.parseInt()`                                                        | 문자열 → 정수 변환             |
| **6. 출력 최적화**            | `StringBuilder`                                                             | 여러 줄 출력 시 속도 개선         |
| **7. 출력**                | `System.out.print(sb.toString());`                                          | 마지막에 한 번에 출력            |

---
## 5.참고 팁
| 상황                  | 사용 방법                                                      | 설명            |
| ------------------- | ---------------------------------------------------------- | ------------- |
| **정수 1개 입력**        | `int n = Integer.parseInt(br.readLine());`                 | 바로 정수 변환      |
| **문자열 1줄 입력**       | `String s = br.readLine();`                                | 그대로 문자열로 저장   |
| **여러 정수 입력(공백 구분)** | `StringTokenizer st = new StringTokenizer(br.readLine());` | 반복문으로 여러 개 읽기 |
| **줄 단위 입력 반복**      | `while ((line = br.readLine()) != null) { ... }`           | 파일 끝까지 처리 가능  |
| **문자열 쪼개기 (split)** | `String[] arr = line.split(" ");`                          | 간단하지만 속도는 느림  |

---
## 6. 활용 포인트
- 입력이 많을수록 BufferedReader가 유리

- 공백 단위 입력은 StringTokenizer
(split()보다 빠르고 메모리 효율적)

- 출력은 StringBuilder로 모아서 한 번에 출력
(System.out.println() 여러 번 호출은 느림)

- 마지막 출력은 System.out.print() 사용
(자동 개행 중복 방지)
