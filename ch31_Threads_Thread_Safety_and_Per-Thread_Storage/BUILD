cc_library (
name = 'strerror_unsafe',
srcs = [
	'strerror_unsafe.c',
],
incs = [
	'../ch03_lib',
],
deps = [
	'//ch03_lib:lib',
],

)
cc_library (
name = 'strerror_tsd',
srcs = [
	'strerror_tsd.c',
],
incs = [
	'../ch03_lib',
],
deps = [
	'//ch03_lib:lib',
],

)
cc_binary (
name = 'strerror_test',
srcs = [
	'strerror_test.c',
],
incs = [
	'../ch03_lib',
],
deps = [
	'//ch03_lib:lib',
    '#pthread',
    ':strerror_unsafe',
    ':strerror_tsd',
],

)
