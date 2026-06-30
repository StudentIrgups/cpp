## Task1 

[sql script](./_task1/song_database.sql)

![alter](./_task1/0.png)

![alter](./_task1/1.png)

## Task2

```

create table if not exists employ (
	id serial primary key,
	name varchar(60),
	department varchar(100),
	manager_id integer references employ(id)
);


```

![alter](./_task2/0.png)

![alter](./_task2/1.png)