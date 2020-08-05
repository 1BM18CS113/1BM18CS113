CREATE TABLE flights(
    flno INT PRIMARY KEY,
    fromm VARCHAR(30),
    too VARCHAR(30),
    dist INT,
    depart TIMESTAMP, 
    arrive TIMESTAMP,
    price INT
);

INSERT INTO flights VALUES(1, 'helo', 'hell', 20, '02-12-2000 11:34:00', '02-11-2000 11:34:00', 20000);
INSERT INTO flights VALUES(1, 'helo', 'hell', 20, '02-12-2000 11:34:00', '02-11-2000 11:34:00', 20000);
INSERT INTO flights VALUES(1, 'helo', 'hell', 20, '02-12-2000 11:34:00', '02-11-2000 11:34:00', 20000);
INSERT INTO flights VALUES(1, 'helo', 'hell', 20, '02-12-2000 11:34:00', '02-11-2000 11:34:00', 20000);
INSERT INTO flights VALUES(1, 'helo', 'hell', 20, '02-12-2000 11:34:00', '02-11-2000 11:34:00', 20000);
INSERT INTO flights VALUES(1, 'helo', 'hell', 20, '02-12-2000 11:34:00', '02-11-2000 11:34:00', 20000);

select * from flights;




CREATE TABLE aircraft(
    aid INT PRIMARY KEY,
    aname VARCHAR(30),
    arange INT
);

INSERT INTO aircraft VALUES(1, 'MALAYSIAN AIRLINES', 20000);
INSERT INTO aircraft VALUES(2, 'KINGFISHER AIRLINES', 30000);
INSERT INTO aircraft VALUES(3, 'QUEENFISHER AIRLINES', 12000);
INSERT INTO aircraft VALUES(4, 'LION AIRLINES', 3000);
INSERT INTO aircraft VALUES(5, 'BEAR AIRLINES', 100000);
INSERT INTO aircraft VALUES(6, 'TORTOISE AIRLINES', 50000);
select * from aircraft;



CREATE TABLE certified(
    eid INT,
    aid INT,
    PRIMARY KEY(eid, aid),
    FOREIGN KEY(eid) REFERENCES employee(eid),
    FOREIGN KEY(aid) REFERENCES aircraft(aid)
);
INSERT INTO certified VALUES(3, 1);
INSERT INTO certified VALUES(3, 2);
INSERT INTO certified VALUES(3, 3);
INSERT INTO certified VALUES(3, 4);
INSERT INTO certified VALUES(3, 5);
INSERT INTO certified VALUES(3, 6);
INSERT INTO certified VALUES(1, 1);
INSERT INTO certified VALUES(2, 2);
INSERT INTO certified VALUES(4, 1);
INSERT INTO certified VALUES(4, 2);
INSERT INTO certified VALUES(4, 6);
INSERT INTO certified VALUES(5, 5);
INSERT INTO certified VALUES(6, 1);
INSERT INTO certified VALUES(6, 4);
INSERT INTO certified VALUES(6, 3);
select * from certified;




CREATE TABLE employee(
    eid INT PRIMARY KEY,
    ename VARCHAR(30),
    salary INT
);
INSERT INTO employee VALUES(1, 'SAGAR', 90000);
INSERT INTO employee VALUES(2, 'MANGAL', 63000);
INSERT INTO employee VALUES(3, 'DRUDESH', 100000);
INSERT INTO employee VALUES(4, 'MISHEIF', 80000);
INSERT INTO employee VALUES(5, 'MOHAMMAD', 20300);
INSERT INTO employee VALUES(6, 'AQBAR', 84000);
INSERT INTO employee VALUES(7, 'NOT EMPL 1', 84000);
INSERT INTO employee VALUES(8, 'NOT EMPL 2', 2000);
select * from employee;







-- Find the names of aircraft such that all pilots certified to operate them have salaries more than 80K

select aname from aircraft
where aircraft.aid in(
    select aid from certified, employee
    where certified.eid = employee.eid and employee.salary > 80000
);


--  For each pilot who is certified for more than three aircrafts, find the eid and the maximum cruising
--  range of the aircraft for which she or he is certified.