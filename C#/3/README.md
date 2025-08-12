**표준입력**이란?

     표준입력(Standard Input) 은 원래 Unix 시스템에서 나온 개념으로,  
     프로그램이 실행될 때 데이터를 입력받는 기본 통로를 의미


주요 입력 소스

    - 파일 (예: CSV, Excel, 텍스트 파일)
    - 키보드 (사용자가 직접 입력)
    - 실행 시 지정 (프로그램 실행 시 인자 전달)

 
표준입력 비교 (Java vs C#)

| 언어  | 기본 클래스 / 메서드 | 반환 타입 | 숫자 변환 |
|-------|----------------------|-----------|-----------|
| Java  | `Scanner.nextLine()` / `nextInt()` | 타입 다양 | 자동 변환 지원 |
| C#    | `Console.ReadLine()` | string    | `int.Parse()` 또는 `Convert.ToInt32()` 필요 |




Java 예시

    Scanner sc = new Scanner(System.in);
    String name = sc.nextLine();
    int age = sc.nextInt();

C# 예시

    string name = Console.ReadLine();
    int age = int.Parse(Console.ReadLine());
