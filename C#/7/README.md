# 클래스/오브젝트 개요 (C# vs Java)

## 공통 개념
- **클래스(Class)**: 상태(필드)와 동작(메서드)을 묶은 설계도
- **오브젝트(Object)**: 클래스로부터 생성된 실체 (`new` 로 생성)
- **캡슐화/상속/다형성** 등 OOP 핵심은 양쪽 모두 동일

---

## 주요 차이 포인트

| 구분 | C# | Java |
|-----|----|------|
| **필드 접근 관용구** | `프로퍼티(Property)`를 권장 (get/set) | `필드 + getter/setter` 메서드 관용 |
| **프로퍼티 문법** | `public string Name { get; set; }` (자동 구현) | 별도 메서드 작성 필요 |
| **오버라이드 키워드** | `virtual` / `override` / `abstract` | `@Override`(애너테이션), `abstract` |
| **클래스 봉인** | `sealed class` | `final class` |
| **메서드/필드 봉인** | `sealed override` 가능 | `final` 메서드 |
| **정적 멤버** | `static` (둘 다 동일) | `static` |
| **상수/읽기전용** | `const`, `readonly` | `static final`, `final` |
| **네임스페이스/패키지** | `namespace` | `package` |
| **레코드** | `record`(값 중심 타입) | `record`(Java 16+) |
| **구조체** | `struct` (값 타입) 제공 | 없음(유사 개념 X) |
| **속성/이벤트** | 이벤트/델리게이트 내장 | 표준 문법 없음(라이브러리로 해결) |

> 요약: **C#은 Property가 내장**되어 있어 “필드 캡슐화”가 더 간단함.  
> 나머지 OOP 개념은 거의 동일.

---

## 예시: Player 클래스

### C# (Property 중심)
```csharp
namespace Game;

public class Player
{
    // 자동 구현 프로퍼티(캡슐화 권장)
    public string Name { get; set; } = "paiza";
    public string Job  { get; set; } = "魔法使い";
    public int    Hp   { get; private set; } = 120; // 읽기 공개, 쓰기 제한

    // 생성자
    public Player(string name, string job, int hp = 120)
    {
        Name = name;
        Job  = job;
        Hp   = hp;
    }

    // 메서드
    public void Attack()  => Console.WriteLine($"{Name} が攻撃した！");
    public void Move()    => Console.WriteLine($"{Name} が移動した");
}

```

---

### Java (getter/setter 관용)
```java
package game;

public class Player {
    private String name = "paiza";
    private String job  = "魔法使い";
    private int hp      = 120;

    public Player(String name, String job, int hp) {
        this.name = name;
        this.job  = job;
        this.hp   = hp;
    }
    public Player(String name, String job) { this(name, job, 120); }

    public String getName() { return name; }
    public void   setName(String v) { name = v; }

    public String getJob() { return job; }
    public void   setJob(String v) { job = v; }

    public int  getHp() { return hp; }
    // setHp를 막아 캡슐화(읽기 전용 효과)
    // public void setHp(int v) { hp = v; }

    public void attack() { System.out.println(name + " が攻撃した！"); }
    public void move()   { System.out.println(name + " が移動した"); }
}

```

---

# 상속/다형성 문법 비교
## C#
```csharp
public abstract class Character
{
    public virtual void Attack() => Console.WriteLine("Character Attack");
}

public class Wizard : Character
{
    public override void Attack() => Console.WriteLine("Wizard Spell!");
}
```

--- 
## Java
```Java
public abstract class Character {
    public void attack() { System.out.println("Character Attack"); }
}

public class Wizard extends Character {
    @Override public void attack() { System.out.println("Wizard Spell!"); }
}
```

---

### 기억 포인트

- 개념은 거의 동일, 문법만 조금 다름

- **C# = Property 내장** → 캡슐화가 간단, 읽기/쓰기 제어가 명시적

- **Java = getter/setter 관용**, Lombok/record 등으로 보일러플레이트 줄이기도 함

- 봉인/추상/정적/상수 등은 이름만 조금 다르며 의미는 유사
