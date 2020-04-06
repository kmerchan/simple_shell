# Shelly: Simple Shell
Shelly is a simple shell that takes in user input to run commands and arguments.

## Description
Commands and arguments are read, parsed and tokenized, and forked to child processes that execute the program associated with the input command(s). For further information on how specific functions work, please view the [shell flowchart] (https://drive.google.com/file/d/14b2P1kjzZGcs633gdYSbWUm_fyOewNq-/view?usp=sharing).

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
Kelsie Merchant, 1708@holbertonschool.com
Tim McMacken, 1646@holbertonschool.com

## Authors and Acknowledgement
Kelsie Merchant and Tim McMacken
