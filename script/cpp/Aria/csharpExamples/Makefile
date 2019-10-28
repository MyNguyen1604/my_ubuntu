
ifndef MONO
MONO=mono
endif

ifndef MCS
MCS=mcs
endif


all: $(patsubst %.cs,%.exe,$(wildcard *.cs))

%.exe: %.cs ../csharp/AriaCS.dll
	@echo $^
	$(MCS) -out:$@ -r:../csharp/AriaCS.dll $<

info:
	@echo host=$(host)
	@echo "MCS=$(MCS)"
	@echo "MONO=$(MONO)"
