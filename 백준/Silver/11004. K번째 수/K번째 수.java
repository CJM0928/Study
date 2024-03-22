import java.io.*;

public class Main {

    BufferedReader br;

    BufferedWriter bw;

    int [] A;

    int N;

    int K;

    private void quickSortUtil() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        String [] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);
        A = new int[N];

        input = br.readLine().split(" ");
        for(int i=0; i<N; i++){
            A[i] = Integer.parseInt(input[i]);
        }

        quickSort(A,0,N-1,K-1);

        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(A[K-1] +" ");

        bw.flush();
    }

    private void quickSort(int []A, int start, int end , int K){
        if(start < end){
            int pivot = Partition(A,start,end);
            if(pivot == K){
                return;
            }
            if(K < pivot){
                quickSort(A,start,pivot-1,K);
            }else{
                quickSort(A,pivot+1,end,K);
            }
        }
    }

    private int Partition(int[] A, int start, int end){
        if(start+1 == end){
            if(A[start] > A[end]){
                swap(A,start,end);
                return end;
            }
        }
        int middle = (start+end)/2;
        swap(A,start,middle);
        int pivot = A[start];   // 중간에있는 인덱스를 start위치로 이동후, pivot을 둬서, 제 위치 찾아가게함

        int i = start+1;
        int j = end;

        while(i <= j){
            while(j >= start+1 && pivot < A[j]){
                j--;
            }
            while(i <= end && pivot > A[i]){
                i++;
            }
            if(i <= j){         // i와 j를 이동하다가 중간에 막히면 swap을함.
                swap(A,i++,j--);
            }
        }
        A[start] = A[j];
        A[j] = pivot;
        return j;
    }

    private void swap(int []A, int start, int end){
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;
    }

    public static void main(String[] args) throws IOException{
        Main App = new Main();

        App.quickSortUtil();
    }
}
