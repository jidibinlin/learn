create database spjdb;

create table S(
	sno char(2) not null,
	constraint ps1 primary key(sno),
	sname char(10) not null,
	status smallint,
	constraint cs1 check(status >0),
	city char(10)
);

create table P(
	pno char (2) not null,
	constraint pp1 primary key(pno),
	pname char(10) not null,
	color char(2),
	weight smallint,
	constraint cp1 check (weight > 0),
);

create table J(
	jno char(2) not null,
	constraint J1 primary key(jno),
	jname char(10) not null,
	city char(10)
);

create table SPJ(
	sno char(2) not null,
	constraint spjf1 foreign key(sno) references s(sno),
	pno char(2) not null,
	constraint spjf2 foreign key(pno) references p(pno),
	jno char(2) not null,
	constraint spjf3 foreign key(jno) references J(jno),
	qty smallint,
	constraint spjc check (qty>0),
	constraint spjp primary key(sno,pno,jno),
);

create index SPJindex on SPJ(sno asc,pno asc, jno desc);


insert into S(SNO,SNAME,STATUS,CITY)
values ('S1','精益','20','天津'),
('S2','盛锡','10','北京'),
('S3','东方红','30','北京'),
('S4','丰泰盛','20','天津'),
('S5','为民','30','上海');

insert into P(pno,pname,color,weight)
values('P1','螺母','红','12'),
('P2','螺栓','绿','17'),
('P3','螺丝刀','蓝','14'),
('P4','螺丝刀','红','14'),
('P5','凸轮','蓝','40'),
('P6','齿轮','红','30');


insert into J(jno,jname,city)
values
('J1','三建','北京'),
('J2','一汽','长春'),
('J3','弹簧厂','天津'),
('J5','机车厂','唐山'),
('J6','无线电厂','常州'),
('J7','半导体厂','南京');

insert into J(jno,jname,city)
values('J4','造船厂','天津');

insert into SPJ(sno,pno,jno,qty)
values ('S1','P1','J3',100),
('S1','P1','J1',200),
('S1','P1','J4',700),
('S1','P2','J2',100),
('S2','P3','J1',400),
('S2','P3','J2',200),
('S2','P3','J4',500),
('S2','P4','J5',400),
('S2','P5','J1',100),
('S2','P5','J2',100),
('S3','P1','J1',200),
('S3','P3','J1',200),
('S4','P5','J1',100),
('S4','P6','J3',300),
('S4','P6','J4',200),
('S5','P2','J4',100),
('S5','P3','J1',200),
('S5','P6','J2',200),
('S5','P6','J4',500);


delete from s
where sno='S1';

delete from P
where pno='P1';

delete from J
where jno='J4';


update S
set sno='S9'
where sno='S2';

update P
set pno='P0'
where pno='P2';

update P
set weight=-1
where weight=12;


select sno
from SPJ
where jno='j1';

select sno
from SPJ
where jno='j1'and pno='p1';

select sno
from p,spj
where spj.pno=p.pno
	and color='红'and jno='j1';

select j1.jno
from J j1
where jno not in
(select spj.jno
from spj,s,p
where s.sno=spj.sno
and p.pno=spj.pno
and color='红'
and city='天津');

select jno
from spj spj1
where not exists(
	select *
	from spj spj2
	where spj2.sno='s1' and not exists(
		select *
		from spj spj3
		where spj2.pno=spj3.pno and spj1.jno=spj3.jno
	)
);


select Sname,city
from S;

select pname,color,weight
from p;


select jno
from spj
where sno='s1';

select pno,qty
from spj
where jno='j2';

select pno
from spj,s
where spj.sno=s.sno and city='上海';

select jname
from spj,s,j
where spj.sno=s.sno and j.jno=spj.jno and s.city='上海';

select jno
from spj,s
where spj.sno=s.sno and city <> '天津';

update p
set color='蓝'
where color='红';

update spj
set sno='s3'
where sno='s5' and jno='j4' and pno='p6';

delete 
from spj
where sno='s2';

delete 
from s
where sno='s2';

insert into s(sno,sname,status,city)
values
('s2','盛锡',20,'北京');

insert into spj(sno,pno,jno,qty)
values
('s2','p4','j6',200);




