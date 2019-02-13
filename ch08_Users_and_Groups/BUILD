cc_library (
name = 'ugid_functions',
srcs = [
    'ugid_functions.c',
],
incs = [
    '../ch03_lib',
],
deps = [
    '//ch03_lib:lib',
],
)
cc_binary (
name = 'check_password',
srcs = [
    'check_password.c',
],
incs = [
    '../ch03_lib',
],
deps = [
    '//ch03_lib:lib',
    '#crypt',
],
)
cc_binary (
name = 't_getpwent',
srcs = [
    't_getpwent.c',
],
incs = [
    '../ch03_lib',
],
deps = [
    '//ch03_lib:lib'
],
)
cc_binary (
name = 't_getpwnam_r',
srcs = [
    't_getpwnam_r.c',
],
incs = [
    '../ch03_lib',
],
deps = [
    '//ch03_lib:lib'
],
)
