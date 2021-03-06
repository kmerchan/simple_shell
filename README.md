# Shelly: Simple Shell
Shelly is a simple shell that takes in user input to run commands and arguments.

## Description
Commands and arguments are read, parsed and tokenized, and forked to child processes that execute the program associated with the input command(s). For further information on the interaction of specific processes in shell, please view the version 0.1 [shell flowchart] (https://drive.google.com/file/d/14b2P1kjzZGcs633gdYSbWUm_fyOewNq-/view?usp=sharing).

## Style
Shelly and her associated functions follow betty style in accordance with the Holberton School style guide.

## Usage
Shelly has two modes: interactive and non-interactive.
### Interactive:
The user is prompted with a command line.  Commands with or without arguments can be input to the program, just like a typical BASH shell.
Example:
```bash
$ ls
files.c  main.c  shelly.c
$ ./shelly
shelly$ /bin/ls
files.c  main.c  shelly.c
shelly$
shelly$ exit
$
```

### Non-Interactive:
Commands and arguments can be piped into the Shelly program.
Example:
```bash
$ echo "/bin/ls" | ./shelly
files.c  main.c  shelly.c
$
```

## Support
For help using Shelly, please contact:
Kelsie Merchant, kelsie.merchant@holbertonschool.com
Tim McMacken, tim.mcmacken@holbertonschool.com

## Authors and Acknowledgement
Kelsie Merchant and Tim McMacken
