# Instructions

This is the current state of each instruction implementation.

### Transfer Instructions

- [ ] **LDA** load accumulator
- [ ] **LDX** load X
- [ ] **LDY** load Y
- [ ] **STA** store accumulator
- [ ] **STX** store X
- [ ] **STY** store Y
- [ ] **TAX** transfer accumulator to X
- [ ] **TAY** transfer accumulator to Y
- [ ] **TSX** transfer stack pointer to X
- [ ] **TXA** transfer X to accumulator
- [ ] **TXS** transfer X to stack pointer
- [ ] **TYA** transfer Y to accumulator

### Stack Instructions

- [ ] **PHA** push accumulator
- [ ] **PHP** push processor status register (with break flag set)
- [ ] **PLA** pull accumulator
- [ ] **PLP** pull processor status register

### Decrements & Increments

- [ ] **DEC** decrement (memory)
- [ ] **DEX** decrement X
- [ ] **DEY** decrement Y
- [ ] **INC** increment (memory)
- [ ] **INX** increment X
- [ ] **INY** increment Y

### Arithmetic Operations

- [x] **ADC** add with carry (prepare by CLC)
- [x] **SBC** subtract with carry (prepare by SEC)

### Logical Operations

- [ ] **AND** and (with accumulator)
- [ ] **EOR** exclusive or (with accumulator)
- [ ] **ORA** (inclusive) or with accumulator

### Shift & Rotate Instructions

- [ ] **ASL** arithmetic shift left (shifts in a zero bit on the right)
- [ ] **LSR** logical shift right (shifts in a zero bit on the left)
- [ ] **ROL** rotate left (shifts in carry bit on the right)
- [ ] **ROR** rotate right (shifts in zero bit on the left)

### Flag Instructions

- [x] **CLC** clear carry
- [x] **CLD** clear decimal (BCD arithmetics disabled)
- [x] **CLI** clear interrupt disable
- [x] **CLV** clear overflow
- [x] **SEC** set carry
- [x] **SED** set decimal (BCD arithmetics enabled)
- [x] **SEI** set interrupt disable

### Comparisons

- [ ] **CMP** compare (with accumulator)
- [ ] **CPX** compare with X
- [ ] **CPY** compare with Y

### Conditional Branch Instructions

- [ ] **BCC** branch on carry clear
- [ ] **BCS** branch on carry set
- [ ] **BEQ** branch on equal (zero set)
- [ ] **BMI** branch on minus (negative set)
- [ ] **BNE** branch on not equal (zero clear)
- [ ] **BPL** branch on plus (negative clear)
- [ ] **BVC** branch on overflow clear
- [ ] **BVS** branch on overflow set

### Jumps & Subroutines

- [ ] **JMP** jump
- [ ] **JSR** jump subroutine
- [ ] **RTS** return from subroutine

### Interrupts

- [ ] **BRK** break / software interrupt
- [ ] **RTI** return from interrupt

### Other

- [ ] **BIT** bit test (accumulator & memory)
- [ ] **NOP** no operation




# Sources

I'd like to thank these wonderful people whose articles helped me understand most of the concepts
related to implementing and understanding the 6502 microprocessor into an emulator.

---

- **6502 instruction set:** https://www.masswerk.at/6502/6502_instruction_set.html
- **The CARRY flag and OVERFLOW flag in binary arithmetic**: http://teaching.idallen.com/dat2343/10f/notes/040_overflow.txt