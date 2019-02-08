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

## All Valid Symbols 

| Operation | Symbol |
|:---------:|:------:|
| Not       | ~      |
| Or        | + or \||
| And       | \&     |
| Implies   | -\>    |
| If and Only If | \<-\> |
| Equals    | =      |
| Not Equals| !=     |

_More symbols may be added in the future_
