.PHONY: ctarget rtarget clean ctarget-phase1

ctarget:
	gdb $@ -x $@.gdbscript

rtarget:
	gdb $@ -x $@.gdbscript

ctarget-phase1:
	./hex2raw < phase1.HEX > phase1.raw
	./ctarget -q < phase1.raw

clean:
	rm -f *.o *.raw
