# Write your MySQL query statement below
SELECT uni.unique_id, e.name FROM Employees as e LEFT JOIN EmployeeUNI as uni ON  uni.id = e.id 