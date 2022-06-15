## Problem
Write an SQL query to find all dates' `Id` with higher temperatures compared to its previous dates (yesterday).

Return the result table in **any order**.
```
>Table: `Weather`
```+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id is the primary key for this table.
This table contains information about the temperature on a certain day.
```

### Example 
```
Input: 
Weather table:
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
Output: 
+----+
| id |
+----+
| 2  |
| 4  |
+----+
```

## Solution

<!-- use self join and datediff -->
```sql
select w1.id 
from Weather w1, Weather w2 
where datediff(w1.recordDate, w2.recordDate)=1  # determing the previous day by taking difference as 1
and w1.temperature > w2.temperature
```

Besides this solution, this is another solution using `lag` and `datediff`
```sql
with weather_ct as (
select id,recordDate, temperature,
    LAG(temperature) OVER (ORDER BY recordDate) as tmp_yest,
    LAG(recordDate) OVER (ORDER BY recordDate) as yest
from Weather)

select id 
from weather_ct
where temperature > tmp_yest
and datediff(recordDate, yest) = 1
```

This is an amazing solution, I never see this `subdate` before
```sql
select w1.id as id
from Weather w1
    join 
    Weather w2 on w2.recordDate = SUBDATE(w1.recordDate, 1)
    and w1.Temperature > w2.Temperature
```