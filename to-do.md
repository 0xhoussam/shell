# TODO

## Parsing

- [x] parse command name
- [x] parse args
- [x] test args parser
- [x] parse io
- [x] parse redirection
- [x] test command name parser
- [x] test redirection parser
- [x] main loop
- [x] test io parser
- [x] parse ;
- [x] parse and ( && )
- [x] parse |
- [x] parse or ( || )
- [ ] parse double quotes
- [ ] test && parser
- [ ] parse wildcard
- [ ] test wildcard parser
- [ ] test || parser
- [ ] make heredoc del a linked list
- [ ] parse single quotes
- [ ] handle multiple heredoc
- [ ] loop in the first line in expand it
- [ ] make cmd name expand variables

## Execution

- [ ] handle multiple heredoc
- [ ] handle exit value of a process
- [ ] update get_command_path.c
- [ ] free pipes after execution of each process
- [ ] free params after execution of each process
- [ ] exit with valid exit value
- [ ] replace get_next_line with readline in heredoc handler
