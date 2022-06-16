# TODO

## Parsing

- [x] parse command name
- [x] parse args
- [x] parse io
- [x] parse redirection
- [x] test redirection parser
- [x] main loop
- [x] parse ;
- [x] parse and ( && )
- [x] parse |
- [x] parse or ( || )
- [x] make cmd name expand variables
- [x] make args parse double quotes
- [*] parse wildcard *

## Execution

- [ ] handle multiple heredoc
- [ ] handle exit value of a process
- [ ] update get_command_path.c
- [ ] free pipes after execution of each process
- [ ] free params after execution of each process
- [ ] exit with valid exit value
- [ ] replace get_next_line with readline in heredoc handler
