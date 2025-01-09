include ../config.mk

SOURCES := cmath iostream vector

TARGETS := $(addsuffix .gcm, $(SOURCES))
FIND_CMD := find $(PATH_BMI) -name

all: $(TARGETS)

clean:
	@for target in $(TARGETS); do \
		$(FIND_CMD) $$target -exec rm -f {} +; \
	done

%.gcm:
	$(eval OUTPUT_PATH := $(shell $(FIND_CMD) $@))
	@if [ -z "$(OUTPUT_PATH)" ]; then\
		echo "Generating $@"; \
		$(C++) $(CFLAGS) $(CMI_MAPPER) -x c++-system-header $*; \
	else \
		echo "Found $(OUTPUT_PATH), skip generate"; \
	fi
