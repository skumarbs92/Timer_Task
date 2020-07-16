IF EXIST a.exe (
     del a.exe
)

gcc app/src/main.c drv/TIMER/src/timer.c

pause