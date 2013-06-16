# 生成静态库
mylib:mylib(add.o creat.o find.o readfile.o studentList.o stu_govern_main.o writefile.o averageSort.o delete.o login.o sort.o teacherList.o)
	ar - ruv $@ $?
	rm -f $?

add.o: add.c stu_govern.h
	gcc -c add.c 
creat.o:creat.c stu_govern.h
	gcc -c creat.c
find.o:find.c stu_govern.h
	gcc -c find.c
readfile.o:readfile.c stu_govern.h
	gcc -c readfile.c
studentList.o:studentList.c stu_govern.h
	gcc -c studentList.c 
stu_govern_main.o:stu_govern_main.c stu_govern.h
	gcc -c stu_govern_main.c
writefile.o:writefile.c stu_govern.h
	gcc -c writefile.c
averageSort.o:averageSort.c stu_govern.h
	gcc -c averageSort.c
delete.o:delete.c stu_govern.h
	gcc -c delete.c
login.o:login.c stu_govern.h
	gcc -c login.c
sort.o:sort.c stu_govern.h
	gcc -c sort.c
teacherList.o:teacherList.c stu_govern.h
	gcc -c teacherList.c


# gcc stu_govern_main.c -static ./mylib -o stu_govern_main

.PHONY:clean
clean:
	rm -f *.o
