## SRP (Single Responsibility Principle) 예제 정리

“클래스는 단 하나의 이유로만 변경되어야 한다.”

→ 한 클래스는 한 가지 역할만 담당해야 한다.

--- 

### 책임
- Employee는 도메인 데이터(직원 정보)와 그 비즈니스 로직만 가진다.
- 저장, 출력, 이메일 전송 등의 I/O 로직은 절대 포함하지 않는다.

---

### SRP 적용 이유

| 항목                    | 설명                   |
| --------------------- | -------------------- |
| **Employee**          | 도메인 데이터 및 행위(규칙)만 담당 |
| **Repository**        | 데이터 저장/조회 책임         |
| **Printer**           | 표현/출력 책임             |
| **EmailService**      | 이메일 전송 책임            |
| **OnboardingService** | 전체 유스케이스 조합 담당       |

→ 각 클래스가 한 가지 책임만 가지므로  
테스트, 유지보수, 교체가 쉬워진다.  

--- 

### SRP 외의 설계 원칙들 (SOLID 5원칙)

| 약자    | 원칙명                                       | 설명                                                |
| ----- | ----------------------------------------- | ------------------------------------------------- |
| **S** | **Single Responsibility Principle (SRP)** | 단일 책임 원칙 — 클래스는 한 가지 책임만 가져야 한다                   |
| **O** | **Open/Closed Principle (OCP)**           | 개방-폐쇄 원칙 — 확장에는 열려 있고, 수정에는 닫혀 있어야 한다             |
| **L** | **Liskov Substitution Principle (LSP)**   | 리스코프 치환 원칙 — 하위 클래스는 상위 클래스의 기능을 대체할 수 있어야 한다     |
| **I** | **Interface Segregation Principle (ISP)** | 인터페이스 분리 원칙 — 클라이언트가 자신이 사용하지 않는 메서드에 의존하지 않아야 한다 |
| **D** | **Dependency Inversion Principle (DIP)**  | 의존 역전 원칙 — 구체 클래스가 아니라 **추상(인터페이스)**에 의존해야 한다     |

---

### 예시로 보면

| 원칙      | 간단한 예                                                                                  |
| ------- | -------------------------------------------------------------------------------------- |
| **SRP** | `EmployeeRepository`와 `EmployeePrinter`를 분리                                            |
| **OCP** | `EmailService`를 바꿀 때도 기존 코드를 수정하지 않음                                                   |
| **LSP** | `FileEmployeeRepository`가 `EmployeeRepository`를 그대로 대체 가능                              |
| **ISP** | `Printer`와 `EmailService`를 각각 분리해서 사용자가 필요한 기능만 의존                                     |
| **DIP** | `EmployeeOnboardingService`는 구현체가 아니라 인터페이스에 의존 (`EmailService`, `EmployeeRepository`) |


--- 
### 기본 디렉토리 구조

```
solid-principles/  
├── README.md                     # 전체 개요 (SOLID 5원칙 소개)  
├── SRP/  
│   ├── README.md                 # SRP 개념 + 코드 설명  
│   ├── domain/  
│   │   └── Employee.java  
│   ├── repository/  
│   │   ├── EmployeeRepository.java  
│   │   └── InMemoryEmployeeRepository.java    
│   ├── printer/  
│   │   ├── EmployeePrinter.java  
│   │   └── ConsoleEmployeePrinter.java  
│   ├── email/  
│   │   ├── EmailService.java  
│   │   └── DummyEmailService.java  
│   ├── service/  
│   │   └── EmployeeOnboardingService.java  
│   └── App.java  
├── OCP/  
│   └── ...  
├── LSP/  
│   └── ...  
├── ISP/  
│   └── ...  
├── DIP/  
│   └── ...  
```

---
