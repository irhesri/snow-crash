
```nasm
level14@SnowCrash:~$ gdb getflag 
...
(gdb) disassemble main
Dump of assembler code for function main:
...
   0x08048de3 <+1181>:	jmp    0x8048e2f <main+1257>
   0x08048de5 <+1183>:	mov    0x804b060,%eax
   0x08048dea <+1188>:	mov    %eax,%ebx
   0x08048dec <+1190>:	movl   $0x8049220,(%esp)
   0x08048df3 <+1197>:	call   0x8048604 <ft_des>
   0x08048df8 <+1202>:	mov    %ebx,0x4(%esp)
...
End of assembler dump.
```

```nasm
(gdb) break main
Breakpoint 1 at 0x804894a
(gdb) run
Starting program: /bin/getflag 

Breakpoint 1, 0x0804894a in main ()
(gdb) jump *0x08048de5
Continuing at 0x8048de5.
7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
...
```

```sh
level14@SnowCrash:~$ su flag14
Password: 
Congratulation. Type getflag to get the key and send it to me the owner of this livecd :)
```

