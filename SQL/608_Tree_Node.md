## Question
Write an SQL query to report the type of each node in the tree, and return the result table **ordered** by `id` in **ascending** order.

### example
```
    1
   / \
  2   3
 / \
4   5

Input: 
Tree table:
+----+------+
| id | p_id |
+----+------+
| 1  | null |
| 2  | 1    |
| 3  | 1    |
| 4  | 2    |
| 5  | 2    |
+----+------+
Output: 
+----+-------+
| id | type  |
+----+-------+
| 1  | Root  |
| 2  | Inner |
| 3  | Leaf  |
| 4  | Leaf  |
| 5  | Leaf  |
+----+-------+
```

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| p_id        | int  |
+-------------+------+
id is the primary key column for this table.
Each row of this table contains information about the id of a node and the id of its parent node in a tree.
The given structure is always a valid tree.
```
Each node in the tree can be one of three types:
* **Leaf**: if the node is a leaf node
* **Root**: if the node is the root of the tree
* **Inner**: if the node is neither a leaf node nor a root node.

## Solution 1
```sql
select id,
    case when p_id is null then "Root"
        when id in (select t.p_id from Tree t) then "Inner"
        else "Leaf" end as type
    from Tree
    order by id;
```
## Solution 2
```sql
select id, 'Root' as type from Tree
where p_id is null
union
select id, 
if (id in (select p_id from Tree), 'Inner', 'Leaf') as type from Tree
where p_id is not null;
```

## Key
Use `case when` in sql in Solution 1
Use `UNION` and `if` in Solution 2