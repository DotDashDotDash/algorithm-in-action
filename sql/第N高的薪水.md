## 第N高的xins

### 题目描述

编写一个 SQL 查询，获取 Employee 表中第 n 高的薪水（Salary）。

```sql
+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
```

例如上述 Employee 表，n = 2 时，应返回第二高的薪水 200。如果不存在第 n 高的薪水，那么查询应返回 null。

```sql
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+
```

[题目来源](https://leetcode-cn.com/problems/nth-highest-salary/)

### 解题思路

`procedure`中可以创建变量，既然取N高，那么首先要去重，偏移量为N-1

### AC

```sql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N := N - 1;
    RETURN (
        # Write your MySQL query statement below.
        select(
            ifnull(
                (
                    select
                        distinct Salary
                    from
                        Employee
                    order by
                        Salary desc
                    limit 1
                    offset N
                ), null
            )
        ) as getNthHighestSalary
    );
END
```