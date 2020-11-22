cc_library(
    name="Set1",
    hdrs=[
    "string_util.h",
    ],
    srcs=[
	"string_util.cpp",
	],
    deps=[
        "@com_google_absl//absl/strings",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "Set1Test",
    srcs = [
    	 "string_util_test.cpp",
    ],
    deps = ["//exercises/set1:Set1",
    "@com_google_absl//absl/strings",
           "@googletest//:gtest_main"],
	   size="small",
)