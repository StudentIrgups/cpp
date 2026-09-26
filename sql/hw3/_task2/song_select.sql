SELECT name, duration
FROM track
where duration = (select max( duration ) from track where name = name )
;

SELECT name, duration
FROM track
WHERE duration >= INTERVAL '3 minutes 30 seconds';

SELECT name, year
FROM collection
WHERE year BETWEEN '2018-01-01' AND '2020-12-31';

SELECT name
FROM performer
WHERE name NOT LIKE '% %';

SELECT name
FROM track
WHERE LOWER(name) LIKE '%my%' 
   OR LOWER(name) LIKE '%мой%';