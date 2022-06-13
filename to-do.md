# TODO

## Parsing

- [x] parse command name
- [x] parse args
- [x] test args parser
- [x] parse io
- [x] parse redirection
- [x] test command name parser
- [x] test redirection parser
- [...] main loop
- [ ] test io parser
- [ ] parse wildcard
- [ ] test wildcard parser
- [ ] parse and ( && )
- [ ] test && parser
- [ ] parse or ( || )
- [ ] test || parser
- [ ] parse |
- [ ] test |
- [ ] parse ;
- [ ] test ; parser
- [ ] make heredoc del a linked list
- [ ] parse double quotes
- [ ] parse single quotes

## Execution

- [ ] handle multiple heredoc
- [ ] handle exit value of a process
- [ ] update get_command_path.c
- [ ] free pipes after execution of each process
- [ ] free params after execution of each process
- [ ] exit with valid exit value
- [ ] replace get_next_line with readline in heredoc handler