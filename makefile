ifeq ($(OS),Windows_NT)
	CC = x86_64-w64-mingw32-gcc
else
	CC = clang
endif

CFLAGS = -Wall -Wextra -Werror -std=c99 -nostdlib -ffreestanding -O3 -pedantic -ffp-contract=off

# Unfortunately, I have found that make quite often selects the wrong shell
# (e.g. PowerShell), so commands like "find" won't work unless we explicitly
# specify bash.  You also can't use a variable for this (e.g. $(SHELL)) as make
# inexplicably tries to read something from the PATH and fails.  So hardcoding a
# reference to bash seems to be the only way to get a working build.
C_FILES = $(shell bash -c "find src -type f -iname ""*.c""")
H_FILES = $(shell bash -c "find src -type f -iname ""*.h""")
O_FILES = $(patsubst src/%.c,obj/%.o,$(C_FILES))
TOTAL_REBUILD_FILES = makefile $(H_FILES)

TESTS = $(patsubst tests/cases/%, %, $(shell bash -c "find tests/cases -mindepth 1 -maxdepth 1 -type d"))

dist/obj_to_c: $(O_FILES)
	mkdir -p $(dir $@)
	$(CC) $(CLAGS) -flto -lm $(O_FILES) -o $@

obj/%.o: src/%.c $(TOTAL_REBUILD_FILES)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(addprefix tests/pass_markers/, $(TESTS))

tests/results/%.c: tests/cases/%/input.obj dist/obj_to_c
	mkdir -p $(dir $@)
	dist/obj_to_c test_object_prefix_ test_material_prefix_ TEST_NAVIGATION_MATERIAL_PREFIX_ TEST_OPAQUE_CUTOUT_PASS_DATA_MACRO_NAME TEST_OPAQUE_PASS_DATA_MACRO_NAME TEST_OPAQUE_DRAW_CALL_DATA_MACRO_NAME TEST_CUTOUT_PASS_DATA_MACRO_NAME TEST_CUTOUT_DRAW_CALL_DATA_MACRO_NAME TEST_OPAQUE_CUTOUT_PASS_MACRO_NAME TEST_OPAQUE_DRAW_CALL_MACRO_NAME TEST_CUTOUT_DRAW_CALL_MACRO_NAME TEST_ADDITIVE_BLENDED_PASS_DATA_MACRO_NAME TEST_ADDITIVE_PASS_DATA_MACRO_NAME TEST_ADDITIVE_DRAW_CALL_DATA_MACRO_NAME TEST_BLENDED_PASS_DATA_MACRO_NAME TEST_BLENDED_DRAW_CALL_DATA_MACRO_NAME TEST_ADDITIVE_BLENDED_PASS_MACRO_NAME TEST_ADDITIVE_DRAW_CALL_MACRO_NAME TEST_BLENDED_DRAW_CALL_MACRO_NAME TEST_NAVIGATION_MACRO_NAME LOCATION_LIST_MACRO_NAME LOCATION_MACRO_NAME RED_LIST_MACRO_NAME RED_MACRO_NAME GREEN_LIST_MACRO_NAME GREEN_MACRO_NAME BLUE_LIST_MACRO_NAME BLUE_MACRO_NAME OPACITY_LIST_MACRO_NAME OPACITY_MACRO_NAME V_LIST_MACRO_NAME V_MACRO_NAME U_LIST_MACRO_NAME U_MACRO_NAME test/include/a.h test/include/b.h test/include/c.h < $< > $@

tests/pass_markers/%: tests/results/%.c tests/cases/%/expected.c
	diff $^
	mkdir -p $(dir $@)
	touch $@

clean:
	rm -rf obj dist tests/results tests/pass_markers
