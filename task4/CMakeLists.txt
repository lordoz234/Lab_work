aux_source_directory(. DIR_SRCS)

foreach(src_file ${DIR_SRCS})
    get_filename_component(exec_name ${src_file} NAME_WE)
    add_executable(${exec_name} ${src_file})
endforeach()
