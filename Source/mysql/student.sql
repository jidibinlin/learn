create database studentdb;
create table student(
	sno char(9) not null,
	constraint p1 primary key(sno),
	sname char(10) not null,
	ssex char(2),
	sage smallint,
	constraint c1 check (sage>=12),
	sdept char(15)

);

create table course(
	cno char(2) not null,
	constraint p2 primary key(cno),
	cname char (20),
	cpno char(2),
	constraint f1 foreign key(cpno) references course(cno),
	ccredit smallint,
);


create table sc(
	sno char(9) not null,
	constraint f2 foreign key(sno) references student(sno),
	cno char(2) not null,
	constraint f3 foreign key(cno) references course(cno),
	constraint p3 primary key(sno,cno),
	grage decimal(5,1) ,
	constraint c2 check(grage>=0 and grage<=100),
)

alter table course alter column cname varchar(40);

alter table student add birthday datetime ;

create index snameindex on student(sname desc);

create unique index cnameindex on course(cname); 

drop index p3;

create clustered index scindex on sc(sno);

insert into student(Sno,Sname,Ssex,Sage,Sdept)
values('200215121','李勇','男','20','CS'),
('200215122','刘晨','女','19','CS'),
('200215123','王敏','女','18','MA'),
('200215125','张立','男','19','IS');


insert into Course(Cno,Cname,Cpno,Ccredit)
values('2','数学',NULL,'2'),
('6','数据处理',NULL,'2');

insert into Course(Cno,Cname,Cpno,Ccredit)
values('4','操作系统','6','3'),
('7','PASCAL语言','6','4');

insert into Course(Cno,Cname,Cpno,Ccredit)
values('5','数据结构','7','4'),
('1','数据库','5','4'),
('3','信息系统','1','4');

insert into Sc(Sno,Cno,grage)
values('200215121','1','92'),
('200215121','3','88'),
('200215121','2','85'),
('200215122','2','90');

insert into Sc(Sno,Cno,grage)
values('200215122','3','80');

delete from Course
where Cno='1';

delete from Sc
where Sno='200215122';

delete from student
where Sno='200215122';


update student
set sno='200215122'
where sno='200215121';

update Student
set sno='200215129'
where sno='200215121';

update student
set Sage='10'
where Sno='200215121';


select *
from course
where ccredit>=2 and cno<=5;

select *
from course
where ccredit>=2 and ccredit<=8;


select cno,cname,ccredit
from course
where cno=1 or cno=7 or cno=4;

select *
from course
where ccredit>=3
order by ccredit;

select *
from sc,student
where sc.sno=student.sno;

select *
from student,sc
where sc.sno=student.sno and sc.grage>=80;

select student.sno,student.sname,sc.grage
from student,sc
where student.sno=sc.sno;

select student.sno,sc.cno,sc.grage
from student,sc
where student.sno=sc.sno and student.sno in(
	select student1.sno
    from student student1,sc sc1
    where student1.sno=student1.sno and sdept='CS'
);

select student.sno,student.sname
from student,sc,course
where student.sno=sc.sno and sc.cno=course.cno and cname='操作系统';

select distinct student.sno,sc.cno,sc.grage
from student,sc,course
where student.sno=sc.sno and exists(
	select *
    from student
    where student.sdept='CS'
);






