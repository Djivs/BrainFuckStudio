# BrainFuckStudio [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/Djivs/BrainFuckStudio/blob/master/LICENSE)

Best 2020 development environment for the BrainFuck programming language

Supports working with files, personal interface customization and working with interpreter

![preview](/img/large_logo.jpg)

[screenshots](https://github.com/Djivs/BrainFuckStudio/tree/master/screenshots)

# Installation and running(Linux)
1. **Download Git LFS [here](https://git-lfs.github.com/)**

Briefly:
- download [this](https://github.com/git-lfs/git-lfs/releases/download/v2.11.0/git-lfs-linux-amd64-v2.11.0.tar.gz)
- extract archive
- open it and run
    ```
    $ git lfs install
    ```
2. **Download this repository using**

```
$ git clone https://github.com/Djivs/BrainFuckStudio
```

3. **Go to folder with shell executable file**

```
cd DistributionKit
```

4. **Run BFIDE.sh**

```
$ ./BFIDE.sh
```

**If shell file running failed with error like this:**

```
Failed to load platform plugin "xcb".
```

**Type this command:**

```
sudo apt-get install -y libxcb-xinerama0
```


**If shell file running failed with error like this:**

```
./BFIDE.sh: line 1: version: command not found
...
```
##### Make sure you installed LFS correctly.
If reinstalling and checking installation guide didn't help you:
- delete DistributionKit folder from your cloned repository
- open repository in terminal and type:
```
git checkout .
```


# Changelog
[Changelog](https://github.com/Djivs/BrainFuckStudio/blob/master/CHANGELOG.md)

# Testing

[Speed Tests](https://github.com/Djivs/BrainFuckStudio/blob/master/SPEEDTESTS.md)

# Used algorithms

[Algs](ALGS.md)

# References
[Repository with codes used for testing](https://github.com/rdebath/Brainfuck/tree/master/testing)

[Wikipedia BF page](https://ru.wikipedia.org/wiki/Brainfuck)

[Page with BF compiler optimizing tips](https://www.nayuki.io/page/optimizing-brainfuck-compiler)

[QT Documentation](https://doc.qt.io/qt-5/)

[License badge source](https://gist.github.com/lukas-h/2a5d00690736b4c3a7ba)

[Git Large File Storage](https://git-lfs.github.com/)

[CQtDeployer](https://github.com/QuasarApp/CQtDeployer)

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
