## LEVEL 00

### STEP 1

- We start by searching the system for any files owned by flag00. These files might hold some clues or even the password itself.

```sh
level00@SnowCrash:~$ find / -user flag00 2>/dev/null 
/usr/sbin/john
/rofs/usr/sbin/john
level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt
level00@SnowCrash:~$ cat /rofs/usr/sbin/john
cdiiddwpgswtgt
```

- We find two files: `/usr/sbin/john` and `/rofs/usr/sbin/john` that both contain `cdiiddwpgswtgt`

- The content looked like a password, but it didn’t work when I tried it directly. Suspecting that the password might be encoded somehow.

### STEP 2

- I used [CacheSleuth](https://www.cachesleuth.com/rot.html#:~:text=Provides%20the%20option%20to%20rotate,25%20either%20encrypted%20or%20decrypted.) to try all the possible ROT shifts. 

After the test, we find that ROT11 gives us a decoded string that makes sense: `nottoohardhere`.

Now we can try logging in as user flag00 and run the getflag command
```sh
level00@SnowCrash:~$ su flag00
Password: 
Don't forget to launch getflag !
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
```