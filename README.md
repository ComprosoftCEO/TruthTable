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
An expression is a series of identifiers connected by operators and parenthesis. For example:
```
(a&b)->(b|~c)<->(c!=b)
```
Identifiers all start with a letter, followed by 0 or more alphanumeric characters. Unary
operators go before an identifier, and binary operators go between an identifier (infix notation).

### All Supported Operators

| Operation | Symbol |  Type  |
|:---------:|:------:|:------:|
| Not       | ~      | Unary  |
| Or        | + or \|| Binary |
| And       | \&     | Binary |
| Exclusive Or | \^  | Binary |
| Implies   | -\>    | Binary |
| If and Only If | \<-\> | Binary |
| Equals    | =      | Binary |
| Not Equals| !=     | Binary | 

_More operators may be added in the future_
