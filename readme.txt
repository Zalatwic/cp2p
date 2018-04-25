cp2p - a chat host for sending communications quickly and simply from the command line

usage: cp2p [FLAGS]  
   flags
      -e [KEY] enable encryption
      -d disallow quering of server options
      -n [NAME] set server name
      -p [PORT] set server port
      -a dissalow usernames
      -f allow sending of files
      -r [FILENAME] record server messages
      -ip log ip of incoming messages
      -dm only dm's to server allowed
      -pm private messages through the server allowed

kon2 - a client for quickly sending communications to cp2p servers

usage: kon2 [HOST] [OPTION] [FLAGS]
   flags:
      -n [NAME] set name
      -c [HEX] set color
      -e [KEY] specify encryption key
      -p [PORT] specify port
