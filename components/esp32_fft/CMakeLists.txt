idf_component_register(SRCS esp32_fft.c INCLUDE_DIRS include)

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wdouble-promotion")
