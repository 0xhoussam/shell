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
- [x] parse wildcard \*
- [x] expand $
- [x] expand \*
- [x] remove ''
- [x] remove ""
- [x] $gg -> input splited. "$gg" input is not splited
- [x] handle the global buffer overflow
- [ ] handle input errors
- [ ] handle redireciton errors
- [ ] handle quotes error
- [ ] handle pipe errors
- [ ] fix asterisk segfults

## Execution

- [x] handle multiple heredoc
- [x] handle exit value of a process
- [x] update get_command_path.c
- [x] free pipes after execution of each process
- [x] free params after execution of each process
- [x] exit with valid exit value
- [x] replace get_next_line with readline in heredoc handler
- [x] change inputs priority in redir_handler
- [x] rewrite builtins
- [x] handle executing relative files (check a file contain . or ..)
- [x] execute heredocs first
- [x] wait for all prev processes on case of && or ||
- [x] do not exit from main process
- [x] serialize command arguments (added in the parser phase)
- [ ] handle echo $?
- [x] fix builtins writing to pipes
- [x] cd: handle not directory, invalid folder names
- [ ] add shell init
- [x] update export sort
- [x] split export argument
- [x] handle export existing variable
- [x] export sort list before printing
- [x] fix pwd old_pwd leak

