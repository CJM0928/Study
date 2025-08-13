# 배열(Array) 사용 사례

## 1. 순서 관리가 필요한 데이터 처리
- 출석 번호, 좌석 순서, 파티의 순서
- 트럼프나 장기 등의 게임 데이터

## 2. Web 폼의 선택지
- 나이, 도도부현(일본의 행정구역) 등

## 3. 엑셀과 같은 다중 행 데이터
- CSV 데이터 처리

# 배열 요소 결합 (Join)

## 1. C#의 `string.Join()`
- 배열이나 컬렉션의 요소를 특정 구분자로 결합해 하나의 문자열로 만든다.
- 구분자는 **요소 사이에만** 들어가며, 앞뒤에는 붙지 않는다.

**예시**

    string[] team = { "勇者", "魔法使い", "戦士" };
    string result = string.Join("・", team);
    Console.WriteLine(result); // 勇者・魔法使い・戦士


## Java의 `String.join()`

- **Java 8 이상**에서 제공되는 메서드
- C#의 `string.Join()`과 동일하게, 배열이나 컬렉션 요소를 특정 구분자로 결합
- 구분자는 **요소 사이에만** 들어가며, 앞뒤에는 붙지 않음
- **카멜 표기법**과 **파스칼 표기법**을 유의하자

**예시**

      String[] team = { "勇者", "魔法使い", "戦士" };
      String result = String.join("・", team);
      System.out.println(result); // 勇者・魔法使い・戦士


#  foreach 문 비교 (Java vs C#)

## 1. C#의 foreach
- 배열이나 컬렉션의 각 요소를 순회하며 읽기 전용 변수로 사용
- 요소 값을 변경할 수 없음
- 구문:  

  foreach (타입 변수명 in 컬렉션) {
      // 처리
  }

  
**예시**

    string[] team = { "勇者", "戦士", "魔法使い" };
    
    foreach (string job in team) {
        Console.WriteLine(job);
    }

## Java의 향상된 for문 (Enhanced for)

    - C#의 `foreach`와 거의 동일한 기능
    - 배열이나 컬렉션의 각 요소를 읽기 전용으로 순회
    - 요소 값을 직접 변경할 수 없음
    
    - 구문:

    for (타입 변수명 : 컬렉션) {
        // 처리
    }


**예시**

    String[] team = { "勇者", "戦士", "魔法使い" };
    
    for (String job : team) {
        System.out.println(job);
    }

## C#의 `Count` vs Java의 `size()`

| 언어  | 요소 개수 확인 방법 | 형태 | 괄호 필요 여부 |
|-------|--------------------|------|---------------|
| C#    | `list.Count`       | 속성(Property) | ❌ 없음 |
| Java  | `list.size()`      | 메서드(Method) | ✅ 있음 |

---

### 예시 (C#)

    var team = new List<string>();
    team.Add("勇者");
    Console.WriteLine(team.Count); // 1

## Java의 `size()` 예시

    import java.util.ArrayList;
    import java.util.List;
    
    List<String> team = new ArrayList<>();
    team.add("勇者");
    System.out.println(team.size()); // 1

# List 요소 추가 (C# vs Java)

## 1. C#의 `Add()` / `Insert()`
| 메서드 | 동작 | 예시 |
|--------|------|------|
| `Add(item)` | 리스트 **끝에** 요소 추가 | `team.Add("魔法使い");` |
| `Insert(index, item)` | 지정한 인덱스에 요소 삽입, 이후 요소를 뒤로 이동 | `team.Insert(1, "忍者");` |

---

**C# 예시**

    var team = new List<string> { "勇者", "戦士" };
    team.Add("魔法使い");       // 끝에 추가
    team.Insert(1, "忍者");    // 인덱스 1에 삽입
    Console.WriteLine(string.Join("・", team));
    // 勇者・忍者・戦士・魔法使い

## 2. Java의 `add()`

Java의 `List` 인터페이스는 `add()` 메서드가 **오버로딩**되어 있어  
C#의 `Add()`와 `Insert()` 역할을 모두 수행할 수 있음.

| 메서드 | 동작 | 예시 |
|--------|------|------|
| `add(element)` | 리스트 **끝에** 요소 추가 | `team.add("魔法使い");` |
| `add(index, element)` | 지정한 인덱스에 요소 삽입, 이후 요소를 뒤로 이동 | `team.add(1, "忍者");` |

**Java 예시**

    import java.util.ArrayList;
    import java.util.List;
    
    List<String> team = new ArrayList<>();
    team.add("勇者");                // 끝에 추가
    team.add("戦士");                // 끝에 추가
    team.add(1, "忍者");             // 인덱스 1에 삽입
    team.add("魔法使い");            // 끝에 추가
    
    System.out.println(String.join("・", team));
    // 勇者・忍者・戦士・魔法使い

# 요소 삭제 (Remove) — C# vs Java

## 1) 기본 삭제 메서드 비교

| 구분 | C# (`List<T>`) | Java (`List<E>`) | 비고 |
|-----|-----------------|------------------|------|
| 값으로 삭제 | `list.Remove(item)` → `bool` 반환 | `list.remove(Object o)` → `boolean` 반환 | **첫 번째 일치 항목**만 삭제 |
| 인덱스로 삭제 | `list.RemoveAt(index)` → `void` | `list.remove(int index)` → `E` (삭제된 요소 반환) | 범위 벗어나면 예외 |
| 조건으로 일괄 삭제 | `list.RemoveAll(Predicate<T>)` → `int` (삭제 개수) | `list.removeIf(Predicate<E>)` (Java 8+) → `boolean` (변경 여부) | 조건 만족 항목 모두 삭제 |
| 전체 삭제 | `list.Clear()` | `list.clear()` | 모든 요소 제거 |

> 비교 기준: C#은 `EqualityComparer<T>.Default`, Java는 `equals()`로 동등성 비교 (문자열은 둘 다 **대소문자 구분**)

---

## 2) 동작 예시

### C# 예시

    var team = new List<string> { "勇者", "戦士", "魔法使い", "戦士" };
    
    team.Remove("戦士");          // true 반환, 첫 번째 "戦士"만 삭제
    // team: ["勇者", "魔法使い", "戦士"]
    
    team.RemoveAt(1);            // 인덱스 1의 "魔法使い" 삭제
    // team: ["勇者", "戦士"]
    
    int removed = team.RemoveAll(x => x.Contains("者"));
    // removed == 2, team: []

## Java의 `remove()` 예시

    import java.util.ArrayList;
    import java.util.Arrays;
    import java.util.List;
    
    List<String> team = new ArrayList<>(
        Arrays.asList("勇者", "戦士", "魔法使い", "戦士")
    );
    
    team.remove("戦士");              // true 반환, 첫 번째 "戦士"만 삭제
    // team: ["勇者", "魔法使い", "戦士"]
    
    team.remove(1);                   // 인덱스 1의 "魔法使い" 삭제, 반환값: "魔法使い"
    // team: ["勇者", "戦士"]
    
    boolean changed = team.removeIf(s -> s.contains("者"));
    // changed == true, team: []

## 자주 하는 실수 (정수 리스트)

    List<Integer> nums = new ArrayList<>(Arrays.asList(1, 2, 3));
    
    nums.remove(1);                     // 인덱스 1을 삭제 (값 2가 삭제됨)
    nums.remove(Integer.valueOf(1));    // 값 1을 삭제
