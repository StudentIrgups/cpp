-- 1. Заполняем жанры
INSERT INTO genre (name) VALUES 
('Rock'),
('Pop'),
('Jazz'),
('Electronic');

-- 2. Заполняем исполнителей
INSERT INTO performer (name) VALUES 
('Queen'),
('Michael Jackson'),
('Miles Davis'),
('Daft Punk'),
('Adele');

-- 3. Связываем исполнителей с жанрами (genrePerformer)
-- Queen -> Rock
INSERT INTO genrePerformer (genre_id, performer_id) VALUES 
((SELECT id FROM genre WHERE name = 'Rock'), (SELECT id FROM performer WHERE name = 'Queen'));

-- Michael Jackson -> Pop
INSERT INTO genrePerformer (genre_id, performer_id) VALUES 
((SELECT id FROM genre WHERE name = 'Pop'), (SELECT id FROM performer WHERE name = 'Michael Jackson'));

-- Miles Davis -> Jazz
INSERT INTO genrePerformer (genre_id, performer_id) VALUES 
((SELECT id FROM genre WHERE name = 'Jazz'), (SELECT id FROM performer WHERE name = 'Miles Davis'));

-- Daft Punk -> Electronic
INSERT INTO genrePerformer (genre_id, performer_id) VALUES 
((SELECT id FROM genre WHERE name = 'Electronic'), (SELECT id FROM performer WHERE name = 'Daft Punk'));

-- Adele -> Pop
INSERT INTO genrePerformer (genre_id, performer_id) VALUES 
((SELECT id FROM genre WHERE name = 'Pop'), (SELECT id FROM performer WHERE name = 'Adele'));

-- 4. Заполняем альбомы
INSERT INTO album (name, year) VALUES 
('A Night at the Opera', '1975-11-21'),
('Thriller', '1982-11-30'),
('Kind of Blue', '1959-08-17'),
('Discovery', '2001-03-12'),
('21', '2011-01-24');

-- 5. Связываем исполнителей с альбомами (performerAlbum)
INSERT INTO performerAlbum (performer_id, album_id) VALUES 
((SELECT id FROM performer WHERE name = 'Queen'), (SELECT id FROM album WHERE name = 'A Night at the Opera')),
((SELECT id FROM performer WHERE name = 'Michael Jackson'), (SELECT id FROM album WHERE name = 'Thriller')),
((SELECT id FROM performer WHERE name = 'Miles Davis'), (SELECT id FROM album WHERE name = 'Kind of Blue')),
((SELECT id FROM performer WHERE name = 'Daft Punk'), (SELECT id FROM album WHERE name = 'Discovery')),
((SELECT id FROM performer WHERE name = 'Adele'), (SELECT id FROM album WHERE name = '21'));

-- 6. Заполняем треки
INSERT INTO track (album_id, name, duration) VALUES 
((SELECT id FROM album WHERE name = 'A Night at the Opera'), 'Bohemian Rhapsody', '5 minutes 55 seconds'),
((SELECT id FROM album WHERE name = 'A Night at the Opera'), 'Love of My Life', '3 minutes 39 seconds'),
((SELECT id FROM album WHERE name = 'Thriller'), 'Billie Jean', '4 minutes 54 seconds'),
((SELECT id FROM album WHERE name = 'Thriller'), 'Beat It', '4 minutes 18 seconds'),
((SELECT id FROM album WHERE name = 'Kind of Blue'), 'So What', '9 minutes 22 seconds'),
((SELECT id FROM album WHERE name = 'Discovery'), 'One More Time', '5 minutes 20 seconds'),
((SELECT id FROM album WHERE name = '21'), 'Rolling in the Deep', '3 minutes 48 seconds');

-- 7. Заполняем сборники (collection)
INSERT INTO collection (track_id, album_id, name) VALUES 
((SELECT id FROM track WHERE name = 'Bohemian Rhapsody'), (SELECT id FROM album WHERE name = 'A Night at the Opera'), 'Greatest Rock Hits'),
((SELECT id FROM track WHERE name = 'Billie Jean'), (SELECT id FROM album WHERE name = 'Thriller'), 'Best of 80s'),
((SELECT id FROM track WHERE name = 'So What'), (SELECT id FROM album WHERE name = 'Kind of Blue'), 'Jazz Classics'),
((SELECT id FROM track WHERE name = 'One More Time'), (SELECT id FROM album WHERE name = 'Discovery'), 'Electronic Dance Party');

-- 8. Связываем сборники с треками (trackCollectino)
-- Сборник 1: Greatest Rock Hits
INSERT INTO trackCollectino (track_id, collection_id) VALUES 
((SELECT id FROM track WHERE name = 'Bohemian Rhapsody'), (SELECT id FROM collection WHERE name = 'Greatest Rock Hits')),
((SELECT id FROM track WHERE name = 'Love of My Life'), (SELECT id FROM collection WHERE name = 'Greatest Rock Hits'));

-- Сборник 2: Best of 80s
INSERT INTO trackCollectino (track_id, collection_id) VALUES 
((SELECT id FROM track WHERE name = 'Billie Jean'), (SELECT id FROM collection WHERE name = 'Best of 80s')),
((SELECT id FROM track WHERE name = 'Beat It'), (SELECT id FROM collection WHERE name = 'Best of 80s'));

-- Сборник 3: Jazz Classics
INSERT INTO trackCollectino (track_id, collection_id) VALUES 
((SELECT id FROM track WHERE name = 'So What'), (SELECT id FROM collection WHERE name = 'Jazz Classics'));

-- Сборник 4: Electronic Dance Party
INSERT INTO trackCollectino (track_id, collection_id) VALUES 
((SELECT id FROM track WHERE name = 'One More Time'), (SELECT id FROM collection WHERE name = 'Electronic Dance Party')),
((SELECT id FROM track WHERE name = 'Rolling in the Deep'), (SELECT id FROM collection WHERE name = 'Electronic Dance Party'));