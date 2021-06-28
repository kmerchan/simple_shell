# Shelly: Simple Shell
Shelly is a simple shell that takes in user input to run commands and arguments.

## Description
Commands and arguments are read, parsed and tokenized, and forked to child processes that execute the program associated with the input command(s). For further information on the interaction of specific processes in shell, please view the version 0.1 [shell flowchart](https://drive.google.com/file/d/14b2P1kjzZGcs633gdYSbWUm_fyOewNq-/view?usp=sharing).
<img src="https://i.ibb.co/sK1GpSr/Screenshot-2021-06-28-12-09-40-AM.png" alt="Snippet of shell flowchart" border="0">

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
* Kelsie Merchant - [GitHub](https://github.com/kmerchan/) / [LinkedIn](https://www.linkedin.com/in/kelsie-merchant-physics/) / [Twitter](https://twitter.com/MerchantKelsie) / [email: kelsie.merchant@holbertonschool.com](kelsie.merchant@holbertonschool.com)
* Tim McMacken - [GitHub](https://github.com/TMcMac) / [LinkedIn](https://www.linkedin.com/in/timmcmacken/) / [Twitter](https://twitter.com/CmdMine) / [email: tim.mcmacken@holbertonschool.com](tim.mcmacken@holbertonschool.com)
