import gdb

class CpuPrinter:
    def __init__(self, val):
        self.val = val

    def to_string(self):
        regx = int(self.val["regx"])
        regy = int(self.val["regy"])
        rega = int(self.val["rega"])
        sp = int(self.val["sp"])
        sr = int(self.val["sr"])
        pc = int(self.val["pc"])
        tmp = int(self.val["tmp"])

        sr_string = f"{sr:09_b}".replace("_", " ")

        return (
            f"6502 CPU ({self.val.address})\n"
            f"  Registers:\n"
            f"      X: {regx:#04x}\n"
            f"      Y: {regy:#04x}\n"
            f"      A: {rega:#04x}\n"
            f"  Stack Pointer:\n"
            f"      SP: {sp:#04x}\n"
            f"  Status Register:\n"
            f"      NV-B DIZC\n"
            f"      {sr_string}\n"
            f"  Program Counter:\n"
            f"      PC: {pc:#06x}\n"
        )

def build_cpu_printer():
    pp = gdb.printing.RegexpCollectionPrettyPrinter("sf02")
    pp.add_printer('cpu', '^cpu$', CpuPrinter)
    return pp

gdb.printing.register_pretty_printer(
    gdb.current_objfile(),
    build_cpu_printer()
)
