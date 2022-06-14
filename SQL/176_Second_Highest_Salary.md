## Question
Table: `Employee`
```
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id is the primary key column for this table.
Each row of this table contains information about the salary of an employee.
```
Write an SQL query to report the second highest salary from the `Employee` table. If there is no second highest salary, the query should report `null`.

### Example
```
Input: 
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
Output: 
+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+
```
```
Input: 
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
+----+--------+
Output: 
+---------------------+
| SecondHighestSalary |
+---------------------+
| null                |
+---------------------+
```

## Solution 1 
Do select max twice is exactly the answer.:shock:
```sql
select 
    max(salary) as SecondHighestSalary from Employee
where
    salary not in (select max(salary) from Employee);
```

## Solution 2
```sql
select 
    ifnull((select distinct salary 
        from employee
        order by salary desc
        limit 1 offset 1), Null)
    as SecondHighestSalary;
```

## Key
If there is only one record or several same records in the table, then return null.

Otherwise sort in descending order and select the second one.