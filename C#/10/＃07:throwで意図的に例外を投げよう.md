## throw で意図的に例外を投げよう (C# ↔ Java 비교)

- throw 를 사용하면 의도적으로 예외를 발생시킬 수 있다.
- 코드 흐름을 강제로 끊고 catch 블록으로 이동하게 만들 수 있다.
- 실제 프로젝트에서는 잘못된 값, 금지된 상태, 실패 조건에서 throw를 매우 자주 사용함.

---

### C# 코드 (해설 포함)
```
using System;

class Lesson10
{
    public static void Main()
    {
        Console.WriteLine("Hello World");

        try
        {
            int number = 2;
            int answer = 100 / number;
            Console.WriteLine(answer);

            // 👇 의도적으로 예외 발생
            throw new Exception("強制エラー");
        }
        catch (DivideByZeroException e)
        {
            Console.WriteLine("0では割り算できません");
            Console.Error.WriteLine(e);
        }
        catch (Exception e)
        {
            // throw new Exception(...) 에 의해 여기가 실행됨
            Console.WriteLine("例外が発生しました");
            Console.Error.WriteLine(e);
        }
        finally
        {
            Console.WriteLine("Hello C#");
        }
    }
}
```

--- 

### 실행 결과
```
Hello World
50
例外が発生しました
System.Exception: 強制エラー
Hello C#
```
➡ 100/2 결과(50) 출력 후
➡ 강제로 던진 Exception("強制エラー") 이 catch로 넘어가고
➡ finally 실행
➡ 정상 종료

---

### throw의 의미

- throw new Exception("메시지")
  - 직접 예외를 생성해서 던짐
  - throw가 실행되는 순간 아래 코드는 실행되지 않음
  - 즉, throw는 강제 중단 + catch로 점프 효과를 가진다
 
---

### 왜 이런 문법이 필요할까?
> 실제 프로젝트에서 예외를 던지는 경우

| 상황          | throw의 역할           |
| ----------- | ------------------- |
| 잘못된 입력      | 프로그램 흐름을 강제로 중단     |
| 금지된 상태 감지   | “여기서 계속하면 위험하다” 방지  |
| 파일/DB 접근 실패 | 상위 코드로 오류 전달        |
| 연산 오류       | 개발자에게 오류 정보 보고      |
| API 실패      | 호출한 코드가 대처하도록 예외 전달 |

---

### Java에서는 이렇게 된다
> Java도 완전히 동일한 개념을 가진다.

```
public class Lesson10 {
    public static void main(String[] args) {
        System.out.println("Hello World");

        try {
            int number = 2;
            int answer = 100 / number;
            System.out.println(answer);

            // 의도적 예외 발생
            throw new Exception("強制エラー");

        } catch (ArithmeticException e) {
            System.out.println("0では割り算できません");
            e.printStackTrace();
        } catch (Exception e) {
            System.out.println("例外が発生しました");
            e.printStackTrace();
        } finally {
            System.out.println("Hello Java");
        }
    }
}
```

---

### C# ↔ Java 비교표

| 기능       | C#                         | Java        | 설명        |
| -------- | -------------------------- | ----------- | --------- |
| 예외 직접 발생 | `throw new Exception(...)` | 동일          | 완전히 같은 문법 |
| 예외 타입    | `Exception`                | `Exception` | 최상위 타입 동일 |
| 흐름 중단    | throw 시 아래 코드 실행 안 됨       | 동일          |           |
| catch 선택 | 타입 매칭                      | 동일          |           |
| finally  | 항상 실행                      | 동일          |           |

