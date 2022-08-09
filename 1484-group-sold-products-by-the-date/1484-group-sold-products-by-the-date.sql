# Write your MySQL query statement below
select sell_date, count( distinct product ) as num_sold ,
    
    GROUP_CONCAT( distinct product order by product ASC separator ',' ) as products
    
        FROM Activities GROUP BY sell_date order by sell_date ASC;
