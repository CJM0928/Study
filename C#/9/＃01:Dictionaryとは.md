## Dictionary の基本機能 (C# ↔ Java Map)

> C# Dictionary 는 “키-값(Key-Value)” 형태의 자료구조이며  
> Java의 HashMap 및 Map 인터페이스와 1:1로 대응된다.

---

### C# – Dictionary 기본 예제

```
using System;
using System.Collections.Generic;

class Lesson08
{
    public static void Main()
    {
        // 키: string, 값: string
        var enemies = new Dictionary<string, string>();

        // 추가(Add)
        enemies.Add("ザコ", "弱いモンスター");
        enemies.Add("中ボス", "ちょっと強いモンスター");
        enemies.Add("ラスボス", "最強のモンスター");

        // 키로 데이터 참조
        Console.WriteLine(enemies["ザコ"]);     // 弱いモンスター
        Console.WriteLine(enemies["中ボス"]);   // ちょっと強いモンスター

        // 키를 변수로 사용하여 접근
        var level = "ラスボス";
        Console.WriteLine(enemies[level]);      // 最強のモンスター

        // 갱신(Update)
        enemies["ザコ"] = "弱すぎるモンスター";

        // 삭제(Remove)
        enemies.Remove("中ボス");

        // 데이터 개수
        Console.WriteLine("Count = " + enemies.Count);
    }
}

```

---

### 출력 예시

```
弱いモンスター
ちょっと強いモンスター
最強のモンスター
Count = 2
```

---

### Dictionary 주요 기능 요약

| 기능    | C# Dictionary                 | 설명              |
| ----- | ----------------------------- | --------------- |
| 추가    | `Add(key, value)`             | 이미 있는 키면 예외 발생  |
| 조회    | `dict[key]`                   | 존재하지 않으면 예외     |
| 안전 조회 | `TryGetValue(key, out value)` | null-safe 방식    |
| 갱신    | `dict[key] = newValue`        | 해당 키가 없으면 새로 생성 |
| 삭제    | `Remove(key)`                 | 성공 여부(bool) 반환  |
| 전체 개수 | `Count`                       | 요소 개수           |

---

### 중요한 특징

- Dictionary는 순서가 없다 (unordered)
  - 배열(List)처럼 위치(index)가 아닌 “키”로 접근한다.

- 같은 키를 두 번 Add 하면 예외 발생
  - 하지만 dict[key] = value는 갱신으로 처리됨

- 키 타입은 자유롭게 가능

```
Dictionary<int, string>
Dictionary<string, Enemy>
Dictionary<WeaponType, int>
```

---

### Java HashMap과 비교
> C# Dictionary ↔ Java HashMap은 거의 같은 기능을 가진다.

```
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Map<String, String> enemies = new HashMap<>();

        enemies.put("ザコ", "弱いモンスター");
        enemies.put("中ボス", "ちょっと強いモンスター");
        enemies.put("ラスボス", "最強のモンスター");

        System.out.println(enemies.get("ザコ"));
        System.out.println(enemies.get("中ボス"));

        String level = "ラスボス";
        System.out.println(enemies.get(level));

        // 갱신
        enemies.put("ザコ", "弱すぎるモンスター");

        // 삭제
        enemies.remove("中ボス");

        System.out.println("Size = " + enemies.size());
    }
}
```

---

### C# ↔ Java Dictionary/Map 비교표

| 기능    | C# Dictionary   | Java Map(HashMap)         | 비고                      |
| ----- | --------------- | ------------------------- | ----------------------- |
| 추가    | `Add(key, val)` | `put(key, val)`           | 존재 키: C# 오류 / Java 덮어쓰기 |
| 조회    | `dict[key]`     | `map.get(key)`            | C#: 키 없으면 예외            |
| 안전 조회 | `TryGetValue()` | `containsKey()` + `get()` | C# 편리                   |
| 삭제    | `Remove(key)`   | `remove(key)`             | 둘 다 삭제 후 bool/obj 반환    |
| 개수    | `Count`         | `size()`                  | 이름만 다름                  |
| 순서    | 없음              | 없음                        | 둘 다 unordered           |

---

### 최종 요약

- Dictionary는 Key → Value 매핑 구조
- Add, Update, Remove, Count 사용해 CRUD 가능
- 키를 문자열, 숫자 등 어떤 타입이든 사용할 수 있음
- Java의 HashMap과 기능이 95% 동일함
- 게임 개발(RPG)에서 몬스터, 아이템 정보 관리 시 매우 유용
