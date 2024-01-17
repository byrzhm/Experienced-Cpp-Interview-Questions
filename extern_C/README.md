#### without `extern "C"`

``` shell
gcc -c cfile.c -o cfile.o
g++ -c app.cpp -o app.o
g++ app.o cfile.o -o prog.exe # undefined reference to 'func()'

# use nm to see the symbol table

nm cfile.o
# 0000000000000000 b .bss
# 0000000000000000 d .data
# 0000000000000000 p .pdata
# 0000000000000000 r .rdata
# 0000000000000000 r .rdata$zzz
# 0000000000000000 t .text
# 0000000000000000 r .xdata
#                  U __imp___acrt_iob_func
#                  U __mingw_vfprintf
# 0000000000000054 T func
# 0000000000000000 t printf

nm app.o
# 0000000000000000 b .bss
# 0000000000000000 d .data
# 0000000000000000 p .pdata
# 0000000000000000 r .rdata$zzz
# 0000000000000000 t .text
# 0000000000000000 r .xdata
#                  U __main
#                  U _Z4funcv # what????????????????
# 0000000000000000 T main
```

#### with `extern "C"`

``` shell
g++ -c app.cpp -o app.o # recompile app.cpp

# use nm to see the symbol table

nm app.o
# 0000000000000000 b .bss
# 0000000000000000 d .data
# 0000000000000000 p .pdata
# 0000000000000000 r .rdata$zzz
# 0000000000000000 t .text
# 0000000000000000 r .xdata
#                  U __main
#                  U func # right!!!!!!!!
# 0000000000000000 T main

# now we can build prog
g++ app.o cfile.o -o prog.exe
```