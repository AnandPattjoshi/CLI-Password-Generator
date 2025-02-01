#!/bin/bash

gcc -o pswd pswd.c

if [ $? -ne 0 ]; then #checks if exit value of the gcc command was anything other 0 or (success)
    echo "Compilation failed. Please check the C source code."
    exit 1
fi

if [ -z "$1" ]; then 
    echo "Usage: $0 <password_length>"
    exit 1
fi

./password_generator $1

ln -sf "$(pwd)/generate_password.sh" /usr/local/bin/pswdgentest
chmod +x /usr/local/bin/pswdgentest