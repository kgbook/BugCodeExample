macro(clear_local_var)
    set(local_module "")
    set(local_source "")
    set(local_include "")
    set(local_cflags "")
    set(local_dependency "")
    set(local_export_header "")
    set(local_link_dir "")
endmacro()

macro(append_source)
    foreach(arg ${ARGV})
        aux_source_directory(${arg} ${arg}_srcs)
        set(local_source ${local_source} ${${arg}_srcs})
    endforeach()
endmacro()

macro(build_static_library)
    add_library(${local_module} STATIC ${local_source})
    target_compile_definitions(${local_module} PUBLIC ${local_cflags})
    target_include_directories(${local_module} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${local_include})
    target_include_directories(${local_module} PUBLIC ${local_export_header})
    target_link_libraries(${local_module} PUBLIC ${local_dependency})
endmacro()

macro(build_prebuilt_static_library)
    add_library(${local_module} STATIC IMPORTED)
    set_target_properties(${local_module} PROPERTIES
            IMPORTED_LOCATION ${local_dependency}
            INTERFACE_INCLUDE_DIRECTORIES ${local_export_header})
endmacro()

macro(build_shared_library)
    add_library(${local_module} SHARED ${local_source})
    target_compile_definitions(${local_module} PUBLIC ${local_cflags})
    target_include_directories(${local_module} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${local_include})
    target_include_directories(${local_module} PUBLIC ${local_export_header})
    target_link_libraries(${local_module} PUBLIC ${local_dependency})
endmacro()

macro(build_object_library)
    add_library(${local_module} OBJECT ${local_source})
    target_compile_definitions(${local_module} PUBLIC ${local_cflags})
    target_include_directories(${local_module}
            PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${local_include}
            PUBLIC ${local_export_header})
    target_link_libraries(${local_module} PUBLIC ${local_dependency})
endmacro()

macro(build_prebuilt_shared_library)
    add_library(${local_module} SHARED IMPORTED GLOBAL)
    set_target_properties(${local_module} PROPERTIES
            IMPORTED_LOCATION ${local_source}
            INTERFACE_INCLUDE_DIRECTORIES ${local_export_header})
endmacro()

macro(build_submodule)
    foreach (submodule ${local_dependency})
        add_subdirectory(${submodule})
    endforeach ()
endmacro()

macro(build_interface_library) # FIXME: it works for CLion, terminal, or Xcode, but issue should be fixed for Android Studio
    add_library(${local_module} INTERFACE)
    target_include_directories(${local_module} INTERFACE ${local_export_header})
    target_link_directories(${local_module} INTERFACE ${local_link_dir})
    target_link_libraries(${local_module} INTERFACE ${local_dependency})
endmacro()

macro(build_executable)
    add_executable(${local_module} ${local_source})
    target_compile_definitions(${local_module} PUBLIC ${local_cflags})
    target_include_directories(${local_module} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${local_include})
    target_link_libraries(${local_module} PUBLIC ${local_dependency})
endmacro()