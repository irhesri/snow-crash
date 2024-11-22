# LEVEL 09

```sh
level09@SnowCrash:~$ ls -l
total 12
-rwsr-sr-x 1 flag09 level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09 level09   26 Mar  5  2016 token
```

**level09:** is a setuid binary, meaning it runs with the permissions of the file owner `flag09`, regardless of the user executing it.
**token:** is a file that is only readable by `flag09`.

```sh
level09@SnowCrash:~$ ./level09 token 
tpmhr
level09@SnowCrash:~$ ./level09 123456789
13579;=?A
level09@SnowCrash:~$ ./level09 abcdefgh
acegikmo
```
Running the `level09` binary with different arguments reveals that the program seems to encrypt the input string by adding each character's index to the character itself.

To reverse the encryption, we write a [decode.c]() program. This program will take the encrypted string and subtract the index from each character to recover the original data.

```sh
level09@SnowCrash:/tmp/tmp.qCCX4MLHCw$ gcc -o decode decode.c 
level09@SnowCrash:/tmp/tmp.qCCX4MLHCw$ ./decode 
f3iji1ju5yuevaus41q1afiuq
```

Now we can try logging in as user flag09 and run the getflag command
```sh
level09@SnowCrash:/tmp/tmp.qCCX4MLHCw$ su flag09
Password: 
Don't forget to launch getflag !
flag09@SnowCrash:~$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
```
