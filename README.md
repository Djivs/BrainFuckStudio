# BrainFuckStudio

Best 2020 development environment for the BrainFuck programming language

![v2.0](/img/v2_0.png)

# Installation and running

- Download this repository using

```
$ git clone https://github.com/Djivs/BrainFuckStudio
```

or download repository zip and extract it

- Then, go to folder "build-BFIDE-Desktop_Qt_5_15_0_GCC_64bit-Debug", open this folder in terminal and run program:

```
$ ./BFIDE 
```



# Using BrainFuckStudio

#### Starting or ending code execution

- To run code, press F5 or go to Execute -> Start Code

You can't change sell size or input separator while code is running, for obvious reasons.

While code is executing, status changes to "loading".

- To stop code execution, go to Execute -> End Code

When code is executed, or code execution stopped, status changes to "executed in" + execution time

#### Input and output

- While code is executing, output updates every 10 milliseconds
- You need to type text to input text buffer before starting code execution.

#### BrainFuck Interpreter settings

- You can change cell size in "Cell Size" group box (default cell size is 8 bytes)
- You can change input separator in "Input separator" group box. (default input separator is space)

BrainFuckStudio ignores all symbols, that equals to input separator in Input text buffer.

#### BrainFuckStudio style changing

- You can change BrainFuckStudio color scheme in "Color Scheme" group box
-  You  can change output text buffer and code editing text buffer text buffer using separators.

#### BrainFuckStudio code editing

- To clear code editing text buffer, go to Edit -> Clear

# Testing

[Speed Tests](https://github.com/Djivs/BrainFuckStudio/blob/88b46d23b27b8383f874476346809a6726a30f68/SPEEDTESTS.md)

# License:

```
MIT License

Copyright (c) 2020 Trifonov Dmitriy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```