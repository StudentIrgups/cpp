-- Добавляем альбомы 2019-2020 годов (для запроса №2 и №4)
INSERT INTO album (name, year) VALUES 
('Future Nostalgia', '2020-03-27'),
('When We All Fall Asleep', '2019-03-29');

-- Связываем новые альбомы с исполнителями
-- Предположим, что добавим новых исполнителей или используем существующих
INSERT INTO performer (name) VALUES ('Dua Lipa'), ('Billie Eilish');

INSERT INTO performerAlbum (performer_id, album_id) VALUES 
((SELECT id FROM performer WHERE name = 'Dua Lipa'), (SELECT id FROM album WHERE name = 'Future Nostalgia')),
((SELECT id FROM performer WHERE name = 'Billie Eilish'), (SELECT id FROM album WHERE name = 'When We All Fall Asleep'));

-- Добавляем треки в новые альбомы
INSERT INTO track (album_id, name, duration) VALUES 
((SELECT id FROM album WHERE name = 'Future Nostalgia'), 'Don''t Start Now', '3 minutes 3 seconds'),
((SELECT id FROM album WHERE name = 'Future Nostalgia'), 'Levitating', '3 minutes 23 seconds'),
((SELECT id FROM album WHERE name = 'When We All Fall Asleep'), 'Bad Guy', '3 minutes 14 seconds'),
((SELECT id FROM album WHERE name = 'When We All Fall Asleep'), 'Ocean Eyes', '3 minutes 20 seconds');

-- Связываем новых исполнителей с жанрами
INSERT INTO genrePerformer (genre_id, performer_id) VALUES 
((SELECT id FROM genre WHERE name = 'Pop'), (SELECT id FROM performer WHERE name = 'Dua Lipa')),
((SELECT id FROM genre WHERE name = 'Pop'), (SELECT id FROM performer WHERE name = 'Billie Eilish'));

-- Добавляем сборник, в который входит конкретный исполнитель (например, Queen)
INSERT INTO collection (track_id, album_id, name, year) VALUES 
((SELECT id FROM track WHERE name = 'Bohemian Rhapsody'), 
 (SELECT id FROM album WHERE name = 'A Night at the Opera'), 
 'Queen Forever', '2014-01-01');

INSERT INTO trackCollectino (track_id, collection_id) VALUES 
((SELECT id FROM track WHERE name = 'Bohemian Rhapsody'), (SELECT id FROM collection WHERE name = 'Queen Forever')),
((SELECT id FROM track WHERE name = 'Love of My Life'), (SELECT id FROM collection WHERE name = 'Queen Forever'));