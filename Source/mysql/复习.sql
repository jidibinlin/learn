alter table Course add Ccredit2 char(10) NULL;


alter table Course drop Ccredit2;


alter table Course add constraint fk foreign key(Cpno) references Cno;


create unique index Course_cno_index
on Course(Cno); 

drop index Course_cno_index on Course;

show create table Course;

SELECT * FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE;

show index from Course;


select student.sno,sname,ssex,sage,sdept,cno,grage
from student left outer join sc on (student.sno=sc.sno)
order by sage;
