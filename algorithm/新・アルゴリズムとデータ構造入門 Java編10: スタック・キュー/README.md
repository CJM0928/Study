스택    선입 후출(FILO)

큐      선입 선출(FIFO)

Push = 요소를 Input 하는거
Pop = 요스를 remove 하는거

기본 로직은 이런 형태

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

// Push 와 Pop 구현

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

// Push , Pop 응용 예
// '('을 입력 받았더라면, push
// ')'을 입력 받았더라면 pop을 시도함

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
