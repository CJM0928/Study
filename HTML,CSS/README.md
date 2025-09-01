# 1. 레이아웃(위치·배치)

| 속성                               | 설명                                                    | 예시                                        |
| -------------------------------- | ----------------------------------------------------- | ----------------------------------------- |
| `position`                       | 요소의 위치 기준 (static, relative, absolute, fixed, sticky) | `position: fixed;`                        |
| `top`, `right`, `bottom`, `left` | 위치 오프셋(px, %, em 단위)                                  | `top: 10px; left: 20px;`                  |
| `display`                        | 박스 표시 방법                                              | `block`, `inline`, `flex`, `grid`, `none` |
| `flex` 관련                        | Flexbox 레이아웃 제어                                       | `justify-content: center;`                |
| `grid` 관련                        | Grid 레이아웃 제어                                          | `grid-template-columns: 1fr 1fr;`         |
| `float`                          | 요소를 왼쪽/오른쪽으로 띄움 (옛날 방식)                               | `float: left;`                            |
| `z-index`                        | 겹치는 순서 (값이 클수록 위에 표시)                                 | `z-index: 10;`                            |

---

# 2. 크기·간격

| 속성                       | 설명          | 예시                              |
| ------------------------ | ----------- | ------------------------------- |
| `width`, `height`        | 요소의 너비/높이   | `width: 200px; height: 100px;`  |
| `max-width`, `min-width` | 최대/최소 너비 제한 | `max-width: 800px;`             |
| `margin`                 | 바깥 여백       | `margin: 10px; margin: 0 auto;` |
| `padding`                | 안쪽 여백       | `padding: 8px 12px;`            |
| `border`                 | 테두리         | `border: 1px solid #ccc;`       |
| `box-sizing`             | 크기 계산 방식    | `box-sizing: border-box;`       |

---

# 3. 텍스트·폰트

| 속성               | 설명    | 예시                                   |
| ---------------- | ----- | ------------------------------------ |
| `font-size`      | 글자 크기 | `font-size: 16px;`                   |
| `font-family`    | 글꼴    | `font-family: "Meiryo", sans-serif;` |
| `font-weight`    | 글자 두께 | `font-weight: bold;`                 |
| `color`          | 글자 색상 | `color: #fff;`                       |
| `text-align`     | 정렬    | `text-align: center;`                |
| `line-height`    | 줄 간격  | `line-height: 1.5;`                  |
| `letter-spacing` | 글자 간격 | `letter-spacing: 2px;`               |

---

# 4. 배경·시각효과

| 속성                 | 설명         | 예시                                       |
| ------------------ | ---------- | ---------------------------------------- |
| `background-color` | 배경색        | `background-color: #000;`                |
| `background-image` | 배경 이미지     | `background-image: url(bg.png);`         |
| `background-size`  | 배경 이미지 크기  | `background-size: cover;`                |
| `opacity`          | 투명도 (0\~1) | `opacity: 0.7;`                          |
| `box-shadow`       | 그림자        | `box-shadow: 0 4px 8px rgba(0,0,0,0.5);` |
| `border-radius`    | 모서리 둥글게    | `border-radius: 8px;`                    |

--- 

# 5. 애니메이션·트랜지션

| 속성           | 설명              | 예시                              |
| ------------ | --------------- | ------------------------------- |
| `transition` | 변화에 애니메이션 효과 부여 | `transition: all 0.3s ease;`    |
| `transform`  | 회전/이동/확대축소      | `transform: rotate(45deg);`     |
| `animation`  | 키프레임 기반 애니메이션   | `animation: blink 1s infinite;` |

---

# 6. 기타

| 속성           | 설명           | 예시                        |
| ------------ | ------------ | ------------------------- |
| `cursor`     | 마우스 커서 모양    | `cursor: pointer;`        |
| `overflow`   | 내용이 넘칠 때 처리  | `overflow: hidden;`       |
| `visibility` | 보이기/숨기기      | `visibility: hidden;`     |
| `clip-path`  | 특정 모양으로 잘라내기 | `clip-path: circle(50%);` |
