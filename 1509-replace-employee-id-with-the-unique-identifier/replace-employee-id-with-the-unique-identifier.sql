# Write your MySQL query statement below
SELECT u.unique_id, e.name FROM Employees as e LEFT JOIN EmployeeUNI as u ON u.id = e.id

