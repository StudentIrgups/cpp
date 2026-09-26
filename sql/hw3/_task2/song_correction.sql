-- Добавляем поле года в таблицу сборников (если его ещё нет)
ALTER TABLE collection ADD COLUMN IF NOT EXISTS year date;

-- Обновляем годы выпуска сборников (2018-2020)
UPDATE collection SET year = '2018-05-01' WHERE name = 'Greatest Rock Hits';
UPDATE collection SET year = '2019-03-15' WHERE name = 'Best of 80s';
UPDATE collection SET year = '2020-11-20' WHERE name = 'Jazz Classics';
UPDATE collection SET year = '2017-01-01' WHERE name = 'Electronic Dance Party';

-- Добавляем треки с русскими названиями, содержащими "мой"
INSERT INTO track (album_id, name, duration) VALUES 
((SELECT id FROM album WHERE name = '21'), 'Мой путь', '4 minutes 10 seconds'),
((SELECT id FROM album WHERE name = 'Discovery'), 'My Way', '3 minutes 50 seconds');