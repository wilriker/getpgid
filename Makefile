# FLAGS
CC ?= gcc
LD = $(CC)
CFLAGS ?= -pedantic -Wall -std=c99
DESTDIR =
PREFIX = /usr
BINDIR = $(PREFIX)/bin
MKDIR = mkdir -p
INSTALL = install
RM = rm -f
RMDIR = rmdir


TARGETS = getpgid

.PHONY: all install
.PHONY: clean

all: $(TARGETS)

%.o: %.c
	$(VERBOSE) $(CC) -c $(CFLAGS) -o $@ $<
	$(VERBOSE) $(CC) -c -o $*.d -MT $@ -MM $<

clean:
	$(call colorecho,RM,$(TARGETS))
	$(VERBOSE) rm -f $(TARGETS)

install: all
	@echo "==> copying files..."
	$(INSTALL) $(TARGETS) '$(DESTDIR)$(BINDIR)/'


uninstall:
	@echo "==> deleting files..."
	-$(foreach TARGET,$(TARGETS),$(RM) '$(DESTDIR)$(BINDIR)/$(TARGET)';)
