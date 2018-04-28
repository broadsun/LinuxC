cc_library(
    name = 'lib',
    srcs = [
        'error_functions.c',
        'get_num.c',
    ],
)
cc_binary(
    name = 'test',
    srcs = [
        'get_num_test.c',
    ],
    deps = [
        ':lib',
    ]
)
