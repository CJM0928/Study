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


