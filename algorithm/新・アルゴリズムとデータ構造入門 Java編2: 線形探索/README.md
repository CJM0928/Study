# 線形探索（선형 탐색, Linear Search）

## 概要
- 一列（線形）に並んだデータに対する探索方法  
- 원하는 데이터를 찾을 때까지 **앞에서부터 하나씩 차례대로 확인**하는 방법  

## 手順 (탐색 절차)
1. 데이터 집합의 **첫 번째 요소부터 시작**한다.
2. 현재 요소가 찾고자 하는 값과 같은지 확인한다.
3. 같으면 탐색 성공 → 해당 위치를 반환한다.
4. 다르면 다음 요소로 이동하여 확인한다.
5. 끝까지 확인했는데도 찾지 못하면 탐색 실패이다.

## 特徴 (특징)
- 구현이 간단하다.
- 데이터가 정렬되어 있지 않아도 사용할 수 있다.
- 탐색 대상이 많아질수록 성능이 저하된다.  
  - 시간 복잡도: **O(n)**

## 線形探索のメリット / デメリット

### ◎ メリット (장점)
- 単純でわかりやすい (단순하고 이해하기 쉽다)
- 実装が容易 (구현이 간단하다)

### △ デメリット (단점)
- 他の探索アルゴリズムと比べて効率が悪い  
  (다른 탐색 알고리즘과 비교했을 때 효율이 떨어진다)


## 擬似コード (의사 코드)

```pseudo
function linearSearch(array, target):
    for i from 0 to array.length - 1:
        if array[i] == target:
            return i  // 찾은 위치 반환
    return -1  // 찾지 못한 경우
```

## Java 実装例 (Java 구현 예시)

```pseudo
public class LinearSearch {
    public static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i; // 위치 반환
            }
        }
        return -1; // 찾지 못한 경우
    }

    public static void main(String[] args) {
        int[] data = {5, 3, 8, 4, 2};
        int target = 4;
        int result = linearSearch(data, target);

        if (result != -1) {
            System.out.println("값 " + target + " 은(는) 인덱스 " + result + " 에 있습니다.");
        } else {
            System.out.println("값 " + target + " 을(를) 찾을 수 없습니다.");
        }
    }
}
```

## 정리 포인트

- 선형 탐색은 단순하지만 비효율적일 수 있다.

- 작은 데이터셋에는 유용하지만, 큰 데이터셋에는 다른 탐색 방법(이진 탐색 등)이 더 적합하다

## 線形探索のパフォーマンス (성능)

- 探索対象となるデータ（검색 대상 데이터）: **100,000 個**
- 探索したいデータ（찾고자 하는 데이터 수）: **10,000 個**

### 最悪の場合 (Worst Case)

- 100,000 × 10,000 = 1,000,000,000 回

즉, 최악의 경우 **10억 번**의 비교 연산이 발생한다.  
→ 데이터 개수가 많아질수록 성능이 급격히 저하된다.
