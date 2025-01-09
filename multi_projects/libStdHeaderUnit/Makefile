include ../config.mk

SOURCES := cmath iostream

TARGETS := $(addsuffix .gcm, $(SOURCES))
FIND_CMD := find $(PATH_BMI) -name

all: $(TARGETS)

clean:
	@for target in $(TARGETS); do \
		$(FIND_CMD)  $$(basename $$target) -exec rm -f {} +; \
	done

%.gcm:
	$(eval GCM_FILE := $(notdir $@))
	$(eval FILE_PATH := $(shell $(FIND_CMD) $(GCM_FILE)))
	@if [ -z "$(FILE_PATH)" ]; then\
		echo "Generating $(GCM_FILE)"; \
		$(C++) $(CFLAGS) $(CMI_MAPPER) -x c++-system-header $*; \
	else \
		echo "Found $(FILE_PATH), skip generate"; \
	fi
