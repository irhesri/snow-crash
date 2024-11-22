# LEVEL 01

## USEFUL:
- [Password File](https://www.geeksforgeeks.org/understanding-the-etc-passwd-file/)
- [Shadow Password File](https://www.techtarget.com/searchsecurity/definition/shadow-password-file)
- [Brute Force Attack](https://www.beyondidentity.com/glossary/brute-force-attack)
- [The Essential Brute Force Attack Guide](https://www.avast.com/c-what-is-a-brute-force-attack)

## STEP 1:
```sh
level01@SnowCrash:~$ cat /etc/passwd | grep flag01
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

- Here, we see the entry for flag01, and the password hash is `42hDRfypTqqnw`. This is a hash of the actual password, which is what we need to crack.

## STEP 2:
- We can use a password-cracking tool in my case used **JohnTheRipper** to try cracking the hash.

- First, we need to prepare the hash by saving it to a file. Once we have the hash in a file, we can attempt to crack it using a [wordlist](https://github.com/brannondorsey/naive-hashcat/releases/download/data/rockyou.txt).

```sh
PC@PC:~$ echo 42hDRfypTqqnw > /tmp/pass.txt | john --wordlist=Documents/rockyou.txt /tmp/pass.txt 
Loaded 1 password hash (descrypt, traditional crypt(3) [DES 128/128 SSE2-16])
No password hashes left to crack (see FAQ)
PC@PC:~$ john --show  /tmp/pass.txt
?:abcdefg

1 password hash cracked, 0 left
```
- As we can see JohnTheRipper has cracked the hash and revealed the password: `abcdefg`

- Now we can try logging in as user flag01 and run the getflag command
```sh
level01@SnowCrash:~$ su flag01
Password: 
Don't forget to launch getflag !
flag01@SnowCrash:~$ getflag
Check flag.Here is your token : f2av5il02puano7naaf6adaaf
```