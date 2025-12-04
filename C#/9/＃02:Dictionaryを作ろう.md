## Dictionary を作ろう (C# ↔ Java Map 비교)

- 이 챕터의 핵심 내용
  - 1. 배열(Array)은 인덱스(index) 로 접근한다
  - 2. Dictionary는 키(key) 로 접근한다
  - 3. 키가 존재하지 않으면 예외 발생
  - 4. 문자열 키로 몬스터 타입을 관리하는 방법을 학습하는 단계

### C# 코드 (해설 주석 포함)

```
using System;
using System.Collections.Generic;

class Lesson09
{
    public static void Main()
    {
        // ---- 배열 예제 ----
        string[] enemyArray = {"スライム", "モンスター", "ドラゴン"};
        Console.WriteLine(enemyArray[0]);
        Console.WriteLine(enemyArray[1]);
        Console.WriteLine(enemyArray[2]);
        Console.WriteLine();

        // ---- Dictionary 생성 ----
        var enemyDictionary = new Dictionary<string, string>();

        // Add(key, value)
        enemyDictionary.Add("ザコ", "スライム");
        enemyDictionary.Add("中ボス", "ドラゴン");
        enemyDictionary.Add("ラスボス", "魔王");

        // 키로 값 읽기
        Console.WriteLine(enemyDictionary["ザコ"]);
        Console.WriteLine(enemyDictionary["中ボス"]);
        Console.WriteLine(enemyDictionary["ラスボス"]);

        Console.WriteLine();

        // 키를 변수로 사용 가능
        var level = "ラスボス";
        Console.WriteLine(enemyDictionary[level]);

        // 존재하지 않는 키 조회 → 예외 발생
        // enemyDictionary["敵"];
    }
}
```

---

### 출력 결과

```
スライム
モンスター
ドラゴン

スライム
ドラゴン
魔王

魔王
```

---

### C# Dictionary 특징

| 항목      | 내용                                 |
| ------- | ---------------------------------- |
| 선언      | `new Dictionary<string, string>()` |
| 추가      | `Add(key, value)`                  |
| 조회      | `dict[key]`                        |
| 없는 키 조회 | **KeyNotFoundException** 발생        |
| 개수      | `Count`                            |

---

### Java로 작성하면 이렇게 됨
> Java에서는 HashMap 또는 Map 인터페이스를 사용한다.

```
import java.util.*;

public class Lesson09 {
    public static void main(String[] args) {
        // ---- 배열 ----
        String[] enemyArray = {"スライム", "モンスター", "ドラゴン"};
        System.out.println(enemyArray[0]);
        System.out.println(enemyArray[1]);
        System.out.println(enemyArray[2]);
        System.out.println();

        // ---- HashMap 생성 ----
        Map<String, String> enemyDictionary = new HashMap<>();

        enemyDictionary.put("ザコ", "スライム");
        enemyDictionary.put("中ボス", "ドラゴン");
        enemyDictionary.put("ラスボス", "魔王");

        System.out.println(enemyDictionary.get("ザコ"));
        System.out.println(enemyDictionary.get("中ボス"));
        System.out.println(enemyDictionary.get("ラスボス"));

        System.out.println();

        String level = "ラスボス";
        System.out.println(enemyDictionary.get(level));

        // 존재하지 않는 키: null 반환
        // System.out.println(enemyDictionary.get("敵")); // null
    }
}
```

---

### C# Dictionary vs Java Map(HashMap)

| 기능      | C# Dictionary              | Java Map(HashMap) | 차이점             |
| ------- | -------------------------- | ----------------- | --------------- |
| 선언      | `Dictionary<TKey, TValue>` | `Map<K, V>`       | 사용 시 Generic 명시 |
| 추가      | `Add(key, val)`            | `put(key, val)`   | 기능 동일           |
| 조회      | `dict[key]`                | `map.get(key)`    | 문법만 다름          |
| 없는 키 조회 | **예외** 발생                  | **null** 반환       | 중요한 차이!         |
| 개수      | `Count`                    | `size()`          | 이름만 다름          |
| 키 변수 사용 | `dict[level]`              | `map.get(level)`  | 동일              |

---

### 가장 중요한 차이

| 항목           | C#                        | Java                      |
| ------------ | ------------------------- | ------------------------- |
| 존재하지 않는 키 조회 | `KeyNotFoundException` 발생 | `null` 반환                 |
| 안전한 조회       | `TryGetValue()`           | `containsKey()` + `get()` |

- C#에서는 키가 없다 → 프로그램이 예외로 중단
- Java에서는 키가 없다 → null을 반환
