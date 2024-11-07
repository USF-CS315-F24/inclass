# ROM Creation Python Scripts

## Overview

- makerom3.py: turns objdump output into a .hex file
- mkdecoderom.py: turns the output bits row of the decoder spreadsheet into a .hex file
- mkasciirom.py: turns the ouput of the mnemonic row of the decoder spreadsheet into a .hex file


## makerom3.py usage

Will will need to be using a RISC-V vm to use `as` and `objdump`.

To create a `.hex` file from a `.o` (obj) file:

```
$ as -o test_s.o test_s.o
$ objdump -d test_s.o | python3 makerom3.py > test_s.hex
```

You can then import `test_s.hex` into an instruction memory ROM.

## mkdecoderom.py usage

To create `output_bits.txt`

```
$ cat > output_bits.txt
<PASTE OUTPUT_BITS COLUMN FROM SPEADSHEET>
^D
```

To create `output_bits.hex`

```
$ cat output_bits.txt | python3 mkdecoderom.py > output_bits.hex
```

You can then import `output_bits.hex` into the instruction decoder ROM.

## mkasciirom.py

To create `debug_rom.txt`:

```
$ cat > debug_rom.txt
<PASTE MNEMONICS COLUMN FROM SPEADSHEET>
^D
```

To create `debug_rom.hex`

```
$ cat debug_rom.txt | python3 mkasciirom.py > debug_rom.hex
```

You can then import `debug_rom.hex` into the debug ROM.

