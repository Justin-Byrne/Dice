# Dice

![issues](https://img.shields.io/github/issues/Justin-Byrne/Dice)
![forks](https://img.shields.io/github/forks/Justin-Byrne/Dice)
![stars](https://img.shields.io/github/stars/Justin-Byrne/Dice)
![license](https://img.shields.io/github/license/Justin-Byrne/Dice)

Dice is a basic program designed in C++ for educational and extracurricular purposes.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Model](#model)
- [Support](#support)
- [Structure](#structure)
- [Copyright](#copyright)

## Installation

Migrate to your desired download location on your local machine using your (either) your console or terminal, and download this repository to your system using git clone:

```sh
git clone https://github.com/Justin-Byrne/Dice.git
```

Initiate the Makefile under (root)/Dice/Dice, within your terminal/shell:

```sh
> make && make clean
```

**Note:** Your compiled binary output will be generated under the *bin* directory, inside the *release* directory. It's from this directory that you can execute your compiled file.

## Usage

Usage for this application can be found by using the `--help` flag, at the prompt:

```sh
> Dice --help

Usage:  Dice D[no] [rolls] <[multi]>

        Options:
                --help          Display this help and exit
                --version       Output version information and exit

        Params:
                [no]            Number associated with the type of dice generated
                [rolls]         Amount of rolls that each dice should be rolled
                [multi]         [Optional]: Multiplier to be applied to the value rolled
```

Presently, there are two primary methods of generating and rolling dice with this program:

1) The following command will generate a single D6, roll it once, and providing the following output:

```sh
# Dice D6 1

 > Results:
        Amount of Dice: 1

 > Generated Dice | [TYPE]: Cube  [SIDES]: 6  [MULTIPLES]: 1  [VALUE]: 3

Total: 3
```

2) The following command will generate two D8 die, roll each of them, and provide the following output with a 10 x multiplier:

```sh
# Dice D8 2 10

 > Results:
        Amount of Dice: 2

 > Generated Dice | [TYPE]: Octahedron  [SIDES]: 8  [MULTIPLES]: 10  [VALUE]: 4
 > Generated Dice | [TYPE]: Octahedron  [SIDES]: 8  [MULTIPLES]: 10  [VALUE]: 3

Total: 70
```

## Model

Basic Model of classes and interface implementations.

![Model](http://byrne-systems.com/content/static/packages/Dice/UML_Basic_Diagram.svg)

## Support

Please [open an issue](https://github.com/Justin-Byrne/Dice/issues/new) for support.

## Structure


	. (master)
	│
	│
	├── Dice
    │   │
    │   │
    │   ├── Dice
    │   │   │
    │   │   ├──bin
    │   │   │   │
    │   │   │   ├── debug
    │   │   │   └───release
    │   │   │
    │   │   ├── doc
    │   │   │   │
    │   │   │   ├── Doxygen
    │   │   │   │   │
    │   │   │   │   ├── html (API Documentation)
    │   │   │   │   │   │
    │   │   │   │   │   ├── index.html (Index to API HTML Documentation)
    │   │   │   │   │   ├── ...
    │   │   │   │   │   └── search
    │   │   │   │   │       │
    │   │   │   │   │       └── ...
    │   │   │   │   │
    │   │   │   │   ├── latex (LATEX Graphics for Documentation)
    │   │   │   │   │   │
    │   │   │   │   │   └── ...
    │   │   │   │   │
    │   │   │   │   ├── rtf (Rich Text Formatting Reference Material)
    │   │   │   │   │   │
    │   │   │   │   │   ├── refman.rtf (API Reference Manual)
    │   │   │   │   │   └── ...
    │   │   │   │   │
    │   │   │   │   └── Doxygen (Save File)
    │   │   │   │
    │   │   │   ├── editor (Sublime Text Editor Files)
    │   │   │   │   │
    │   │   │   │   ├── Dice.sublime─project
    │   │   │   │   └── Dice.sublime─workspace
    │   │   │   │
    │   │   │   ├── models
    │   │   │   │   │
    │   │   │   │   ├── UML Basic Diagram.svg
    │   │   │   │   ├── UML Detailed Diagram.svg
    │   │   │   │   ├── READEME.md
    │   │   │   │   └── ... (Extra files)
    │   │   │   │
    │   │   │   └── CHANGELOG.md
    │   │   │
    │   │   │
    │   │   ├── include
    │   │   │   │
    │   │   │   └── DICE.h
    │   │   │
    │   │   ├── src
    │   │   │   │
    │   │   │   └── DICE.cpp
    │   │   │
    │   │   ├── Main.cpp
    │   │   ├── Makefile
    │   │   ├── Dice.vcxproj
    │   │   └── Dice.vcxproj.filters
    │   │
    │   └── Dice.sln
	│
	├── .gitignore
	├── LICENSE
	└── READEME.md


## Copyright

![Byrne-Systems](http://byrne-systems.com/content/static/cube_sm.png)

== Byrne-Systems © 2019 - All rights reserved. ==