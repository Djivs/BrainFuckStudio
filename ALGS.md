# Code executing

![parsing](/img/parsing.png)

- Parse code — from +, -,[, ] and etc to commands:

**ADD X** — add x to current cell value

**MOV X** - move pointer on X cells

​	if x > 0, move from left to right

​	else move from right to left

**PUT X** - print cell char value X times

**GET X** - scan cell value x times. read the same value more than once is a little bit strange, but who knows?...

**GOTO X** - skip X <u>commands</u>

​	if X < 0, go back to X commands

**ZERO X** - make current cell 0

- How parsing works:

1. Go through all code symbols

2. If code[i] is one of BF commands (+,-,<,> etc)

   1. If previous command is same as current, just increase/decrease **X**
   2. else, add current command with **X** = 1/-1

3. If code[i] is [:

   save this command number in special array, move this array iterator right and add GOTO command

4. if code[i] is ]:

   go to last index in special array - thats number of corresponding [ command

   then, make **X** of corresponding [ equals (] index) - ([ index) and    ]     **X** just as previous but *(-1)

5. If code[i] == [ and code[i+1] == (+ / -) and code[i+2] == ], then current command is ZERO

- Then just run parsed code

# Threading

![threading](/img/threading.png)