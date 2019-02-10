# Truth Table
Boolean Expression Truth Table Builder

<br>

## Compiling
The provided makefile should handle all of the compiling and linking of objects.
However, you need to install the [Flex Lexer](https://www.gnu.org/software/flex/)
and the [Bison Parser](https://www.gnu.org/software/bison/), as the app uses Flex
and Bison to generate the parser. For Debian Linux distros, this is as simple as:
```
sudo apt-get install flex
sudo apt-get install bison
```

<br/>

## Usage
TruthTable \<Expression\>
* __Expression__ - The boolean expression to build a truth table for

<br/>

## Expression
An expression is a series of identifiers or literals connected by operators and parenthesis. For example:
```
[(a&b)->(b|~c)]<->(b!=T)
```
Identifiers all start with a letter, followed by 0 or more alphanumeric characters. Literals are either
`T` or `F` (or any of the variabions listed below). Unary operators go before an identifier, and binary
operators go between an identifier (infix notation).

### Literal Values
| Value | Symbols |
|:----- |:------- |
| True  | True, T, or 1 |
| False | False, F, or 1|

_Note:_ `True` and `False` can be in any case, so `TrUe`, `TRue`, and `TRUE` are all valid.

### All Supported Operators

| Operation | Symbol |  Type  |
|:--------- |:------ |:------:|
| Not       | ~      | Unary  |
| Or        | + or \|| Binary |
| And       | \&     | Binary |
| Exclusive Or | \^  | Binary |
| Implies   | -\>    | Binary |
| If and Only If | \<-\> | Binary |
| Equals    | =      | Binary |
| Not Equals| !=     | Binary | 

_More operators may be added in the future_
