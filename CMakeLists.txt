cmake_minimum_required(VERSION 3.7)
project(kz_corewar)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCE_FILES "./src/*.c" "./includes/*.h" "./Lib/src/ft_printf/*.c"
        "./Lib/src/get_next_line/*.c" "./Lib/src/libft/*.c")
add_executable(kz_corewar ${SOURCE_FILES} src/kz_validation_2.c src/kz_secondary_functions_1.c src/kz_check_param_of_instruction.c)
target_link_libraries(kz_corewar ${CMAKE_SOURCE_DIR}/Lib/big_libft.a)