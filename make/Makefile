ARCH := $(shell uname -m)
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

all:
ifeq ($(ARCH), x86_64)
	$(info on x86_64)
else
	$(info not on x86_64 [$(ARCH)])
endif

$(info mkfile_path: [$(mkfile_path)])
$(info mkfile_dir: [$(mkfile_dir)])
