## Dictionary の基本操作 (C# ↔ Java 比較)

### 이 챕터의 핵심 기능

| 기능             | 설명                  |
| -------------- | ------------------- |
| **조회(Get)**    | `dict[key]`         |
| **개수(Count)**  | 저장된 요소 수            |
| **갱신(Update)** | `dict[key] = value` |
| **삭제(Remove)** | 해당 키를 제거            |


---

### C# 코드 (+ 해설)

```
using System;
using System.Collections.Generic;

class Lesson09
{
    public static void Main()
    {
        // ① Dictionary 생성
        var enemyDictionary = new Dictionary<string, string>();
        enemyDictionary.Add("ザコ", "スライム");
        enemyDictionary.Add("中ボス", "ドラゴン");
        enemyDictionary.Add("ラスボス", "魔王");

        // ② 조회(Get)
        Console.WriteLine(enemyDictionary["ザコ"]);
        Console.WriteLine(enemyDictionary["中ボス"]);
        Console.WriteLine(enemyDictionary["ラスボス"]);

        // ③ Count (요소 개수)
        Console.WriteLine(enemyDictionary.Count);  // 3

        // ④ 갱신(Update)
        enemyDictionary["中ボス"] = "レッドドラゴン";
        Console.WriteLine(enemyDictionary["中ボス"]);  // 레드ドラゴン

        // ⑤ 삭제(Remove)
        enemyDictionary.Remove("ラスボス");
        Console.WriteLine(enemyDictionary.Count);  // 2

        // 없는 키 조회 시 예외 발생
        // enemyDictionary["ラスボス"];
    }
}
```

---

### 출력 결과

```
スライム
ドラゴン
魔王
3
レッドドラゴン
2
```

---

### Java HashMap에서는 어떻게 될까?

```
import java.util.*;

public class Lesson09 {
    public static void main(String[] args) {
        Map<String, String> enemyDictionary = new HashMap<>();
        enemyDictionary.put("ザコ", "スライム");
        enemyDictionary.put("中ボス", "ドラゴン");
        enemyDictionary.put("ラスボス", "魔王");

        // 조회
        System.out.println(enemyDictionary.get("ザコ"));
        System.out.println(enemyDictionary.get("中ボス"));
        System.out.println(enemyDictionary.get("ラスボス"));

        // size
        System.out.println(enemyDictionary.size());

        // 갱신(덮어쓰기)
        enemyDictionary.put("中ボス", "レッドドラゴン");
        System.out.println(enemyDictionary.get("中ボス"));

        // 삭제
        enemyDictionary.remove("ラスボス");
        System.out.println(enemyDictionary.size());

        // 없는 키는 null 반환
        // enemyDictionary.get("ラスボス"); // null
    }
}
```

---

### C# Dictionary ↔ Java Map 비교표

| 기능     | C# Dictionary        | Java HashMap(Map)         | 차이점                              |
| ------ | -------------------- | ------------------------- | -------------------------------- |
| 추가     | `Add(key,val)`       | `put(key,val)`            | Java put은 기존 값을 덮어쓸 수 있음         |
| 조회     | `dict[key]`          | `map.get(key)`            | C#: 없는 키는 **예외**, Java는 **null** |
| 안전한 조회 | `TryGetValue(out)`   | `containsKey()` + `get()` | C#이 더 편함                         |
| 갱신     | `dict[key] = newVal` | `put(key,newVal)`         | 기능 동일                            |
| 삭제     | `Remove(key)`        | `remove(key)`             | 기능 동일                            |
| 개수     | `Count`              | `size()`                  | 이름만 다름                           |

