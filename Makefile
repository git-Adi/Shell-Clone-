each:i1 i2 i3 i4 i5 i6 i7 i8 i9 i10 i11 i12

i1:
	gcc ls_.c -o ls_
i2:
	gcc date_.c -o date_
i3:
	gcc rm_.c -o rm_
i4:
	gcc cat_.c -o cat_
i5:
	gcc mkdir_.c -o mkdir_
i6:
	gcc pwd_.c -o pwd_
i7:
	gcc cat_n.c -o cat_n
i8:
	gcc cat_r.c -o cat_r
i9:
	gcc rm_i.c -o rm_i
i10:
	gcc rm_r.c -o rm_r
i11:
	gcc mkdir_a=r.c -o mkdir_a=r
i12:
	gcc main.c -o main -pthread
	./main