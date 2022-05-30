# Minishell

This is a simple shell like project

## Grammar

```
<letter> ::= a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z
<cmd_name> ::= <letter> | <cmd_name><letter>
<file_name> ::= <letter> | <file_name><letter>
<cmd_end> ::= ";" | "&"
<flag> ::= "-"<letter>
<redirection> ::= ("<" | ">" | "<<" | ">>") <file_name>
<command> ::= <cmd_name> {<flag> <redirection> <cmd_end>}
<cmd_list> :== <command> | <command><command>
<sub_cmd> := "(" <command_list> ")"
```
