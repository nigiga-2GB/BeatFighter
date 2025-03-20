@REM "test.c"をコンパイルするためのバッチファイルです。
@REM 本バッチはGDLから使用されるものではありません。
@REM GDLを使用しないで単体でコンパイルする際に利用してください。
@SET PATH=C:\PROGRA~2\GCCDEV~1\GCCDEV~1\GCC\H8\bin;c:\PROGRA~2\GCCDEV~1\GCCDEV~1\GCC\H8\libexec\gcc\H8300-~1\47-GNU~1.02;c:\PROGRA~2\GCCDEV~1\GCCDEV~1\GCC\H8\H8300-~1\bin
h8300-elf-gcc -I C:\PROGRA~2\GCCDEV~1\GCCDEV~1\TARGET\3048F -L C:\PROGRA~2\GCCDEV~1\GCCDEV~1\TARGET\3048F -mh -nostartfiles -fsigned-char -Wall -Wno-main -pipe -O0 -TC:\PROGRA~2\GCCDEV~1\GCCDEV~1\TARGET\3048F\h8ram.x -Xlinker -Map -Xlinker "test.map" C:\PROGRA~2\GCCDEV~1\GCCDEV~1\TARGET\3048F\h8crt0.s "test.c" -ladd3048 -lm -o "test.exe" 
h8300-elf-objcopy -O srec  "test.exe" "test.mot"
PAUSE
