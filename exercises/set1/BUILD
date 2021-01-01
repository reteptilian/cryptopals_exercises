cc_library(
    name="Set1",
    hdrs=[
    "set_1.h",
    ],
    srcs=[
	"set_1.cpp",
	],
    deps=[
        "@com_google_absl//absl/strings",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "Set1Test",
    srcs = [
    	 "set_1_test.cpp",
    ],
    deps = ["//exercises/set1:Set1",
    "@com_google_absl//absl/strings",
           "@googletest//:gtest_main"],
	   size="small",
)