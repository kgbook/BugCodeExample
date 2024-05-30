clear_local_var()
set(local_module CWE)
file(GLOB sources *.cpp *.h)
set(local_source ${sources})

build_static_library()