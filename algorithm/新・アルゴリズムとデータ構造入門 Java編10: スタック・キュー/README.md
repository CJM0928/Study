# Stack & Queue 정리 (FE 시험 대비)

## 스택 (Stack)
- **정의**: 후입선출 (LIFO: Last In, First Out)
- **주요 연산**
  - `push(x)` : 스택에 요소 x를 넣음
  - `pop()` : 스택에서 가장 위의 요소를 꺼냄
- **활용 예시**
  - 함수 호출 기록 (콜 스택)
  - 깊이 우선 탐색 (DFS)
  - 실행 취소(Undo) 기능

### Java 예시
```java
import java.util.*;

public class StackExample {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();

        stack.push(10);  // push
        stack.push(20);

        System.out.println(stack.pop()); // 20
        System.out.println(stack.pop()); // 10
    }
}
```

## 큐 (Queue)
- **정의**: 선입선출 (FIFO: First In, First Out)
- **주요 연산**
  - `enqueue(x)` : 큐의 뒤에 요소 x를 넣음
  - `dequeue()` : 큐의 앞에서 요소를 꺼냄

- **활용 예시**
  - 프로세스 작업 대기열
  - 너비 우선 탐색 (BFS)
  - 은행·콜센터 같은 대기줄 시뮬레이션

### Java 예시
```java
import java.util.*;

public class QueueExample {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();

        queue.offer(10);  // enqueue
        queue.offer(20);

        System.out.println(queue.poll()); // 10
        System.out.println(queue.poll()); // 20
    }
}

```

--- 
# 여기는 꼭 확인 할 필요는 없음.

### 기본 로직은 이런 형태(배열 형태로 만들어 볾)
```java
    import java.util.*;
    
    public class Main{
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            
            int n = sc.nextInt();
            int last = 0;
            int[] arr = new int[256];
            
            for(int i=0; i<n; i++){
                String query = sc.next();
                if(query.equals("push")){
                    int x = sc.nextInt();
                    arr[last] = x;
                    last++;
                }
            }
            
            for(int j=0; j<last; j++){
                System.out.println(arr[j]);
            }
            
            sc.close();
        }
    }
```

## Push 와 Pop 구현
```java
    import java.util.*;
    
    public class Main{
        public static void main(String[] args) {
    
            Scanner sc = new Scanner(System.in);
    
            char[] stack = new char[256];      // キュー本体
            int stack_size = 0;   // スタックに入っている要素数
    
            int q = sc.nextInt();
            for(int i=0; i<q; i++){
                int query = sc.nextInt();
                if(query == 1){
                    char x = sc.next().charAt(0);
                    // Push
                    stack[stack_size] = x;      
                    stack_size++;
                } else if(query == 2){
                    // Pop
                    stack_size--;           
                }
            }
            for (int j = 0; j < stack_size; j++) {
                System.out.print(stack[j]);
            }
    
            sc.close();
        }
    }
```

## Push , Pop 응용 예
####  '('을 입력 받았더라면 push
#### ')'을 입력 받았더라면 pop을 시도함
```java
    import java.util.*;
    
    public class Main{
        public static void main(String[] args) {
    
            Scanner sc = new Scanner(System.in);
            
            int n = sc.nextInt();
            
            String s = sc.next();
            
            Deque<Character> stack = new ArrayDeque<Character>();
            
            for(int i=0; i<n; i++){
                if(s.charAt(i) == '('){
                    stack.push(s.charAt(i));
                } else if(stack.size() > 0 && stack.peek() == '('){
                    stack.pop();
                }
            }
            
            sc.close();
        }
    }
```
