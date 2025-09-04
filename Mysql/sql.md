# SQL 명령어 분류 표

| 분류                                     | 이름       | 주요 명령어                                               | 설명                                          |
| -------------------------------------- | -----------  | ---------------------------------------------------- | ------------------------------------------- |
| **DDL** (Data Definition Language)     | 데이터 정의어  | `CREATE`, `ALTER`, `DROP`, `TRUNCATE`                | 데이터베이스, 테이블, 뷰, 인덱스 등 **구조(스키마)를 정의/변경/삭제** |
| **DML** (Data Manipulation Language)   | 데이터 조작어  | `SELECT`, `INSERT`, `UPDATE`, `DELETE`               | 테이블에 저장된 **데이터를 조회·삽입·수정·삭제**               |
| **DCL** (Data Control Language)        | 데이터 제어어  | `GRANT`, `REVOKE`                                    | 사용자 권한(접근권한)을 **부여·취소**                     |
| **TCL** (Transaction Control Language) | 트랜잭션 제어어 | `COMMIT`, `ROLLBACK`, `SAVEPOINT`, `SET TRANSACTION` | 트랜잭션을 **확정/취소/임시저장**                        |

--- 

## 간단 암기 팁

- DDL → 구조 정의 (정의)

- DML → 데이터 조작 (조작)

- DCL → 권한 제어 (제어)

- TCL → 트랜잭션 관리 (트랜잭션)

---

### DDL (Data Definition Language)

| 명령어        | 공식 구문                                                                                                     | 설명                 |
| ---------- | --------------------------------------------------------------------------------------------------------- | ------------------ |
| `CREATE`   | `CREATE TABLE 테이블명 (컬럼명 데이터형 [제약조건], ...); `                                                          | 테이블/DB 생성          |
|  `ALTER`   | `ALTER TABLE 테이블명 ADD 컬럼명 데이터형;`                                                                          |     테이블 구조 변경(추가) |
|  `ALTER`   |   `ALTER TABLE 테이블명 MODIFY 컬럼명 데이터형;`                                                                     |     테이블 구조 변경(수정) |
|  `ALTER`   |   `ALTER TABLE 테이블명 DROP COLUMN 컬럼명;`                                                                        |     테이블 구조 변경(삭제) |
| `DROP`     | `DROP TABLE 테이블명; `                                                                                   | 테이블 삭제             |
| `TRUNCATE` | `TRUNCATE TABLE 테이블명; `                                                                               | 데이터 전체 삭제 (구조는 남음) |

---

### DML (Data Manipulation Language)

| 명령어      | 공식 구문                                                         | 설명     |
| -------- | ------------------------------------------------------------- | ------ |
| `SELECT` | `SELECT 컬럼명 FROM 테이블명 WHERE 조건; `                         | 데이터 조회 |
| `INSERT` | `INSERT INTO 테이블명 (컬럼1, 컬럼2, ...) VALUES (값1, 값2, ...); ` | 데이터 삽입 |
| `UPDATE` | `UPDATE 테이블명 SET 컬럼1 = 값1, 컬럼2 = 값2 WHERE 조건; `           | 데이터 수정 |
| `DELETE` | `DELETE FROM 테이블명 WHERE 조건; `                             | 데이터 삭제 |

---

### DCL (Data Control Language)

| 명령어      | 공식 구문                            | 설명          |
| -------- | -------------------------------- | ----------- |
| `GRANT`  | `GRANT 권한 ON 객체 TO 사용자; `    | 사용자에게 권한 부여 |
| `REVOKE` | `REVOKE 권한 ON 객체 FROM 사용자; ` | 사용자 권한 회수   |

---

### TCL (Transaction Control Language)

| 명령어               | 공식 구문                                    | 설명                    |
| ----------------- | ---------------------------------------- | --------------------- |
| `COMMIT`          | `COMMIT; `                           | 트랜잭션 확정 (DB에 영구 반영)   |
| `ROLLBACK`        | `ROLLBACK; `                         | 마지막 COMMIT 이전 상태로 되돌림 |
| `SAVEPOINT`       | `SAVEPOINT 포인트명; ROLLBACK TO 포인트명; ` | 특정 지점까지 롤백            |
| `SET TRANSACTION` | `SET TRANSACTION READ ONLY; `        | 트랜잭션 속성 지정            |

---

## 정리

- DDL: CREATE / ALTER / DROP / TRUNCATE

- DML: SELECT / INSERT / UPDATE / DELETE

- DCL: GRANT / REVOKE

- TCL: COMMIT / ROLLBACK / SAVEPOINT / SET TRANSACTION

---

### MySQL 주요 데이터 타입 정리

| 분류         | 타입                       | 설명                                                       |
| ---------- | ------------------------ | -------------------------------------------------------- |
| **숫자형**    | `INT` / `INTEGER`        | 정수 저장 (약 -21억 \~ +21억)                                   |
|            | `BIGINT`                 | 더 큰 정수 (약 ±9경)                                           |
|            | `SMALLINT`               | 작은 정수 (약 ±3만)                                            |
|            | `DECIMAL(M,D)`           | 고정 소수점 (금액 저장에 주로 사용, 예: DECIMAL(10,2) → 99999999.99 까지) |
|            | `FLOAT`, `DOUBLE`        | 부동소수점 (근사치 계산용, 과학/통계 계산에 사용)                            |
| **문자형**    | `CHAR(n)`                | 고정 길이 문자열 (예: CHAR(10) → 항상 10바이트)                       |
|            | `VARCHAR(n)`             | 가변 길이 문자열 (예: VARCHAR(100) → 최대 100바이트, 실제 글자 수만큼 저장)    |
|            | `TEXT`                   | 긴 문자열 (최대 65,535자, 게시글/설명 저장용)                           |
| **날짜·시간형** | `DATE`                   | 날짜 (YYYY-MM-DD)                                          |
|            | `TIME`                   | 시간 (HH\:MM\:SS)                                          |
|            | `DATETIME`               | 날짜 + 시간 (YYYY-MM-DD HH\:MM\:SS, 범위 넓음)                   |
|            | `TIMESTAMP`              | 날짜 + 시간, **자동 생성·갱신 기능 지원**, 범위 제한 (1970\~2038)          |
| **기타**     | `BOOLEAN` / `TINYINT(1)` | 논리형 (TRUE/FALSE → 내부적으로 0/1 저장)                          |
|            | `BLOB`                   | 이진 데이터 저장 (이미지, 파일 등)                                    |

---

### 제약조건(Constraints)

| 제약조건                      | 구문 예시                                      | 의미 / 특징                                                         |
| ------------------------- | ------------------------------------------ | --------------------------------------------------------------- |
| **PRIMARY KEY**           | `PRIMARY KEY (col)`                        | - 테이블 대표 키<br>- 중복 불가, NULL 불가<br>- 테이블당 1개만 지정 가능              |
| **UNIQUE**                | `UNIQUE (col)`                             | - 값의 고유성 보장<br>- NULL 허용, 중복 불가<br>- 후보키로 활용 가능                 |
| **NOT NULL**              | `col INT NOT NULL`                         | - NULL 값 입력 금지<br>- 반드시 값 입력 필요                                 |
| **DEFAULT**               | `col VARCHAR(20) DEFAULT 'N/A'`            | - 값 입력 없을 때 기본값 자동 할당                                           |
| **CHECK**                 | `CHECK (col > 0)`                          | - 조건식 만족해야 입력 가능<br>- MySQL 8.0부터 동작                            |
| **FOREIGN KEY**           | `FOREIGN KEY (col) REFERENCES parent(col)` | - 다른 테이블 PK/UK 참조<br>- 참조 무결성 보장                                |
| **ON DELETE / ON UPDATE** | `... ON DELETE CASCADE`                    | - 부모 데이터 삭제/수정 시 동작 지정<br>- `CASCADE`, `SET NULL`, `RESTRICT` 등 |

### 제약조건 예시

```
CREATE TABLE employee (
    emp_id INT PRIMARY KEY,             -- PK 지정
    email VARCHAR(100) UNIQUE,          -- UNIQUE 지정
    name VARCHAR(50) NOT NULL,          -- NOT NULL 지정
    status VARCHAR(10) DEFAULT '재직',   -- DEFAULT 지정
    salary INT CHECK (salary > 0),      -- CHECK 지정
    dept_id INT,
    CONSTRAINT fk_dept FOREIGN KEY (dept_id)
        REFERENCES department(dept_id)  -- FK 지정
        ON DELETE CASCADE
);
```

```
CREATE TABLE employee (
    emp_id     INT PRIMARY KEY,               -- PRIMARY KEY : 기본키 지정
    email      VARCHAR(100) UNIQUE,           -- UNIQUE : 고유값만 허용
    name       VARCHAR(50) NOT NULL,          -- NOT NULL : 반드시 값 필요
    status     VARCHAR(10) DEFAULT '재직',    -- DEFAULT : 기본값 지정
    salary     INT CHECK (salary > 0),        -- CHECK : 조건 만족해야 입력 가능
    dept_id    INT,
    CONSTRAINT fk_dept                        -- CONSTRAINT : 제약조건 이름 지정
        FOREIGN KEY (dept_id)                 -- FOREIGN KEY : 외래키 지정
        REFERENCES department(dept_id)        -- REFERENCES : 참조 대상 지정
        ON DELETE CASCADE                     -- 부모 삭제 시 자식도 삭제
        ON UPDATE RESTRICT                    -- 부모 수정 시 거부
);
```

---

### 외래키 동작 옵션

| 옵션              | 설명                                                      | 예시                    |
| --------------- | ------------------------------------------------------- | --------------------- |
| **CASCADE**     | 부모 행이 삭제·수정되면 자식 행도 함께 삭제·수정됨                           | `ON DELETE CASCADE`   |
| **SET NULL**    | 부모 행이 삭제·수정되면 자식 FK 값을 `NULL`로 변경 (자식 FK가 NULL 허용이어야 함) | `ON DELETE SET NULL`  |
| **RESTRICT**    | 부모 행이 참조 중이면 삭제·수정 불가 (MySQL 기본 동작)                     | `ON DELETE RESTRICT`  |
| **NO ACTION**   | 사실상 `RESTRICT`와 동일하게 동작 (MySQL에선 차이 없음)                 | `ON UPDATE NO ACTION` |
| **SET DEFAULT** | 기본값으로 설정 (MySQL InnoDB에서는 지원 안 됨)                       | 지원 X                  |

---

### 요약

- CASCADE = 같이 지움/변경

- SET NULL = 자식값 NULL 처리

- RESTRICT / NO ACTION = 부모 지우기 거부
