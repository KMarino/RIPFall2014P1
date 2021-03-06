# GNU Make solution makefile autogenerated by Premake

ifndef config
  config=release_x64
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),release_x64)
  derplanner_compiler_config = release_x64
  derplanner_runtime_config = release_x64
  derplannerc_config = release_x64
  deps_unittestpp_config = release_x64
  tests_config = release_x64
  example_travel_config = release_x64
  example_blocks_config = release_x64
  example_travel2_config = release_x64
  hanoi_config = release_x64
endif
ifeq ($(config),release_x32)
  derplanner_compiler_config = release_x32
  derplanner_runtime_config = release_x32
  derplannerc_config = release_x32
  deps_unittestpp_config = release_x32
  tests_config = release_x32
  example_travel_config = release_x32
  example_blocks_config = release_x32
  example_travel2_config = release_x32
  hanoi_config = release_x32
endif
ifeq ($(config),debug_x64)
  derplanner_compiler_config = debug_x64
  derplanner_runtime_config = debug_x64
  derplannerc_config = debug_x64
  deps_unittestpp_config = debug_x64
  tests_config = debug_x64
  example_travel_config = debug_x64
  example_blocks_config = debug_x64
  example_travel2_config = debug_x64
  hanoi_config = debug_x64
endif
ifeq ($(config),debug_x32)
  derplanner_compiler_config = debug_x32
  derplanner_runtime_config = debug_x32
  derplannerc_config = debug_x32
  deps_unittestpp_config = debug_x32
  tests_config = debug_x32
  example_travel_config = debug_x32
  example_blocks_config = debug_x32
  example_travel2_config = debug_x32
  hanoi_config = debug_x32
endif

PROJECTS := derplanner-compiler derplanner-runtime derplannerc deps-unittestpp tests example-travel example-blocks example-travel2 hanoi

.PHONY: all clean help $(PROJECTS)

all: $(PROJECTS)

derplanner-compiler:
ifneq (,$(derplanner_compiler_config))
	@echo "==== Building derplanner-compiler ($(derplanner_compiler_config)) ===="
	@${MAKE} --no-print-directory -C . -f derplanner-compiler.make config=$(derplanner_compiler_config)
endif

derplanner-runtime:
ifneq (,$(derplanner_runtime_config))
	@echo "==== Building derplanner-runtime ($(derplanner_runtime_config)) ===="
	@${MAKE} --no-print-directory -C . -f derplanner-runtime.make config=$(derplanner_runtime_config)
endif

derplannerc: derplanner-compiler
ifneq (,$(derplannerc_config))
	@echo "==== Building derplannerc ($(derplannerc_config)) ===="
	@${MAKE} --no-print-directory -C . -f derplannerc.make config=$(derplannerc_config)
endif

deps-unittestpp:
ifneq (,$(deps_unittestpp_config))
	@echo "==== Building deps-unittestpp ($(deps_unittestpp_config)) ===="
	@${MAKE} --no-print-directory -C . -f deps-unittestpp.make config=$(deps_unittestpp_config)
endif

tests: deps-unittestpp derplanner-compiler derplanner-runtime
ifneq (,$(tests_config))
	@echo "==== Building tests ($(tests_config)) ===="
	@${MAKE} --no-print-directory -C . -f tests.make config=$(tests_config)
endif

example-travel: derplanner-runtime
ifneq (,$(example_travel_config))
	@echo "==== Building example-travel ($(example_travel_config)) ===="
	@${MAKE} --no-print-directory -C . -f example-travel.make config=$(example_travel_config)
endif

example-blocks: derplanner-runtime
ifneq (,$(example_blocks_config))
	@echo "==== Building example-blocks ($(example_blocks_config)) ===="
	@${MAKE} --no-print-directory -C . -f example-blocks.make config=$(example_blocks_config)
endif

example-travel2: derplanner-runtime
ifneq (,$(example_travel2_config))
	@echo "==== Building example-travel2 ($(example_travel2_config)) ===="
	@${MAKE} --no-print-directory -C . -f example-travel2.make config=$(example_travel2_config)
endif

hanoi: derplanner-runtime
ifneq (,$(hanoi_config))
	@echo "==== Building hanoi ($(hanoi_config)) ===="
	@${MAKE} --no-print-directory -C . -f hanoi.make config=$(hanoi_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f derplanner-compiler.make clean
	@${MAKE} --no-print-directory -C . -f derplanner-runtime.make clean
	@${MAKE} --no-print-directory -C . -f derplannerc.make clean
	@${MAKE} --no-print-directory -C . -f deps-unittestpp.make clean
	@${MAKE} --no-print-directory -C . -f tests.make clean
	@${MAKE} --no-print-directory -C . -f example-travel.make clean
	@${MAKE} --no-print-directory -C . -f example-blocks.make clean
	@${MAKE} --no-print-directory -C . -f example-travel2.make clean
	@${MAKE} --no-print-directory -C . -f hanoi.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  release_x64"
	@echo "  release_x32"
	@echo "  debug_x64"
	@echo "  debug_x32"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   derplanner-compiler"
	@echo "   derplanner-runtime"
	@echo "   derplannerc"
	@echo "   deps-unittestpp"
	@echo "   tests"
	@echo "   example-travel"
	@echo "   example-blocks"
	@echo "   example-travel2"
	@echo "   hanoi"
	@echo ""
	@echo "For more information, see http://industriousone.com/premake/quick-start"
