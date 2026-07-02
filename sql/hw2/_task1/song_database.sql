create  database songs;

CREATE TABLE IF NOT EXISTS genre (
	id serial primary key,
	name varchar(100)
);

create table if not exists  performer(
	id serial primary key,
	name varchar(60)
); 

create table if not exists genrePerformer (
	genre_id integer not null references genre(id),
	performer_id integer not null references performer(id),
	constraint pk primary key (genre_id, performer_id)
);

create table if not exists album ( 
	id serial primary key,
	name varchar(50),
	year date
);

create table  if not exists performerAlbum (
	id serial primary key,
	performer_id integer not null references performer(id),
	album_id integer not null references  album(id)
);

create  table if not exists track (
	id serial primary key,
	album_id integer not null references album(id),
	name varchar(100),
	duration interval 
);

create table if not exists collection (
	id serial primary key,
	track_id integer not null references track(id),
	album_id integer not null references album(id),
	name varchar(100)
);

create table if not exists trackCollectino(
	track_id integer not null references track(id),
	collection_id integer not null references collection(id)
); 
