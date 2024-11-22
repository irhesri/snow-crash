# LEVEL 01

## USEFUL:
- [Tshark Manual](https://www.wireshark.org/docs/man-pages/tshark.html)

## SOLUTION:
```sh
level02@SnowCrash:~$ ls -l
total 12
----r--r-- 1 flag02 level02 8302 Aug 30  2015 level02.pcap
level02@SnowCrash:~$ scp ~/level02.pcap imane@$IMANE_IP:/tmp
level02.pcap                                                       100% 8302     8.1KB/s   00:00 
```

The task is to analyze the [pcap file](https://ostinato.org/blog/what-are-pcap-files) to find the password using tools like [wireshark](https://www.wireshark.org/) or [tshark](https://tshark.dev/setup/install/).

```sh
imane@IMane-PC:~$ # wireshark -r /tmp/level02.pcap # or
imane@IMane-PC:~$ tshark -r /tmp/level02.pcap -Y "tcp.flags == 0x18" -x
```
> [-Y "tcp.flags == 0x18"] filters the packets to display only those with a [TCP flag](https://gist.github.com/whiskeyalpharomeo/f3e846f8f6e004f84160) set to 0x18. This represents packets with both the ACK (Acknowledgment) and PSH (Push) flags set, which are commonly used to transmit application data.

After breaking down the packets i get the following data:
```
66 74 5f 77 61 62 64 72  7f  7f  7f 4e 44 52 65 6c  7f 4c 30 4c 0d
```
Converting the hexadecimal values to ASCII gives us:
```
f  t  _  w  a  n  d  r DEL DEL DEL  N  D  R  e  l DEL  L  0  L \r
```

- The extracted password from the packets is: `ft_waNDReL0L`


Now we can try logging in as user flag02 and run the getflag command
```sh
level02@SnowCrash:~$ su flag02
Password: 
Don't forget to launch getflag !
flag02@SnowCrash:~$ getflag
Check flag.Here is your token : kooda2puivaav1idi4f57q8iq
```