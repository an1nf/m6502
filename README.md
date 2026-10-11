# MOS6502
> The MOS Technology 6502 (typically pronounced "sixty-five-oh-two" or "six-five-oh-two") is an 8-bit microprocessor that was designed by a small team led by Chuck Peddle for MOS Technology [...]

A minimal MOS6502 emulator and disassembler in portable C. `6502.c` (22 lines, 1838 bytes) contains the CPU core and a test runner. `dis6502.c` (12 lines, 1286 bytes) is a disassembler that uses 65C02 mnemonics. `test1.bin` is a 48 KiB CPU test ROM that loads at `$4000`, and `test1.asm` is its disassembly.

## API

The machine state is held in globals. `m[65536]` is memory, `pc` is the program counter, `a`, `x` and `y` are the registers, `s` is the stack pointer, and `P` is the status byte laid out as `NV-BDIZC`. `init()` resets the registers, `res()`, `nmi()` and `irq()` raise the corresponding interrupts, and `step()` executes one instruction. The `enum` at the top of `6502.c` sets the stack base page (`STK`) and the BRK, NMI, RESET and IRQ vector addresses (`BRKV`, `NMIV`, `RESV`, `IRQV`). To define your own machine, edit the `enum`, load your ROM into `m` inside `main`, call `init(); res();` and then call `step()` in a loop. I/O is done by trapping on `pc`. In the example below, a `RTS` placed at `$FF00` acts as an output routine, so `LDA #$30 / JSR $FF00` prints `0`.

```c
m[0xFF00]=0x60;
init();res();for(;;){step();if(pc==0xFF00)putchar(a);}
```

## References

The original specification is the [MOS 6500 microprocessor preliminary datasheet (May 1976)](https://www.mdawson.net/vic20chrome/cpu/mos_6500_mpu_preliminary_may_1976.pdf). For background on the chip's history and architecture, see the [Wikipedia article on the MOS Technology 6502](https://en.wikipedia.org/wiki/MOS_Technology_6502). [Visual 6502](http://visual6502.org/JSSim/index.html) is a transistor-level simulation that runs in the browser and is useful for checking exact hardware behavior. Klaus Dormann's [6502/65C02 functional tests](https://github.com/Klaus2m5/6502_65C02_functional_tests) are a more exhaustive test suite than [https://github.com/iczelia/tiny6502](test1.bin).
