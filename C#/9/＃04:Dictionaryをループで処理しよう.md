## Dictionary をループで処理しよう (C# ↔ Java Map 비교)

### 요약

- Dictionary는 KeyValuePair<TKey, TValue> 구조로 이루어져 있다.
- foreach(var item in dictionary) 하면 각 요소가 item.Key, item.Value 로 들어온다.
- Java의 Map.Entry<K,V> 와 동일한 개념.

---

### C# 코드 (해설 포함)

```
using System;
using System.Collections.Generic;

class Lesson09
{
    public static void Main()
    {
        var enemyDictionary = new Dictionary<string, string>();
        enemyDictionary.Add("ザコ", "スライム");
        enemyDictionary.Add("中ボス", "ドラゴン");
        enemyDictionary.Add("ラスボス", "魔王");

        // 개별 키 조회
        Console.WriteLine(enemyDictionary["中ボス"]);

        // 전체 반복 처리
        foreach (var enemy in enemyDictionary)
        {
            // enemy: KeyValuePair<string, string>
            Console.WriteLine(enemy.Key + "の" + enemy.Value + "が現れた！");
        }
    }
}
```

---

### 실행 결과
```
ドラゴン
ザコのスライムが現れた！
中ボスのドラゴンが現れた！
ラスボスの魔王が現れた！
```
> **Dictionary는 순서가 없는 구조이기 때문에 출력 순서는 실행할 때마다 달라질 수 있다.**

### KeyValuePair<TKey, TValue> 설명

> foreach (var enemy in enemyDictionary) 에서  
> enemy의 타입은 자동으로 KeyValuePair<string, string> 이 된다.

➡ 하나의 요소는 다음 두 값을 가진다.

- enemy.Key → 사전의 키 (“ザコ”, “中ボス”…)
- enemy.Value → 해당 키의 값 (“スライム”, “ドラゴン”…)

즉:
```
enemyDictionary["ザコ"]  →  スライム
foreach문에서는 enemy.Key="ザコ", enemy.Value="スライム"
```

---

### Java에서의 같은 코드 (Map.Entry 사용)
> Java에서는 Map.Entry<K,V> 를 사용한다.

```
import java.util.*;

public class Lesson09 {
    public static void main(String[] args) {
        Map<String, String> enemyDictionary = new HashMap<>();
        enemyDictionary.put("ザコ", "スライム");
        enemyDictionary.put("中ボス", "ドラゴン");
        enemyDictionary.put("ラスボス", "魔王");

        System.out.println(enemyDictionary.get("中ボス"));

        for (Map.Entry<String, String> enemy : enemyDictionary.entrySet()) {
            System.out.println(enemy.getKey() + "の" + enemy.getValue() + "が現れた！");
        }
    }
}
```

---

### C# Dictionary 반복 vs Java Map 반복 비교표

| 기능       | C#                          | Java                                      | 비고          |
| -------- | --------------------------- | ----------------------------------------- | ----------- |
| 전체 반복    | `foreach(var item in dict)` | `for (Map.Entry<K,V> e : map.entrySet())` | 거의 동일       |
| Key 접근   | `item.Key`                  | `e.getKey()`                              | 문법만 다름      |
| Value 접근 | `item.Value`                | `e.getValue()`                            | 문법만 다름      |
| 타입       | `KeyValuePair<K,V>`         | `Map.Entry<K,V>`                          | 대응 구조       |
| 출력 순서    | 비보장 (unordered)             | 비보장                                       | 둘 다 Hash 기반 |

