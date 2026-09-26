SELECT g.name AS genre, COUNT(gp.performer_id) AS performer_count
FROM genre g
LEFT JOIN genrePerformer gp ON g.id = gp.genre_id
GROUP BY g.name
ORDER BY performer_count DESC;

SELECT COUNT(t.id) AS track_count
FROM track t
JOIN album a ON t.album_id = a.id
WHERE a.year BETWEEN '2019-01-01' AND '2020-12-31';

SELECT a.name AS album, AVG(t.duration) AS avg_duration
FROM album a
JOIN track t ON a.id = t.album_id
GROUP BY a.name
ORDER BY avg_duration DESC;

SELECT p.name
FROM performer p
WHERE p.id NOT IN (
    SELECT pa.performer_id
    FROM performerAlbum pa
    JOIN album a ON pa.album_id = a.id
    WHERE a.year BETWEEN '2020-01-01' AND '2020-12-31'
);

SELECT DISTINCT c.name AS collection_name
FROM collection c
JOIN trackCollectino tc ON c.id = tc.collection_id
JOIN track t ON tc.track_id = t.id
JOIN album a ON t.album_id = a.id
JOIN performerAlbum pa ON a.id = pa.album_id
JOIN performer p ON pa.performer_id = p.id
WHERE p.name = 'Queen';