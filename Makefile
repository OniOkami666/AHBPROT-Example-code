TARGET   = ahbprot_example
BUILD    = build

CC       = powerpc-eabi-gcc
ELF2DOL  = elf2dol

# Machine dependency flags targeting the Wii hardware
MACHDEP  = -DGEKKO -DHW_RVL -mrvl -mcpu=750 -meabi -mhard-float

# Compiler flags
CFLAGS   = -O2 -Wall $(MACHDEP) -Iinclude -I$(DEVKITPRO)/libogc/include

# Linker flags (Cleaned: relies directly on libogc paths)
LDFLAGS  = -g $(MACHDEP) -L$(DEVKITPRO)/libogc/lib/wii -lwiiuse -lbte -logc -lm

# Object files built from src/ directory layout
OBJS     = $(BUILD)/main.o $(BUILD)/ahbprot.o

all: $(BUILD)/$(TARGET).dol

# Compile C files into object files inside the build directory
$(BUILD)/%.o: src/%.c
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into an ELF executable
$(BUILD)/$(TARGET).elf: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

# Convert ELF to Wii .dol file
$(BUILD)/$(TARGET).dol: $(BUILD)/$(TARGET).elf
	$(ELF2DOL) $< $@

clean:
	rm -rf $(BUILD)
