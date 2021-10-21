{
  "targets": [
    {
      "target_name": "swisseph",
      "sources": [
        "src/swisseph.cc",
        "src/date.cc",
				"src/eclipse.cc",
        "src/hel.cc",
        "src/house.cc",
        "src/pos.cc",
        "src/util.cc",
      ],
      "defines": [
        "NAPI_DISABLE_CPP_EXCEPTIONS",
      ],
      "include_dirs": [
        "<!@(node -p \"require(\'node-addon-api\').include\")",
      ],
      "dependencies": [
        "<!(node -p \"require(\'node-addon-api\').gyp\")",
        "deps/swisseph/swisseph.gyp:swissephz"
      ],
      "cflags!": [
        "-fno-exceptions"
      ],
      "cflags_cc!": [
        "-fno-exceptions"
      ],
      "xcode_settings": {
        "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
        "CLANG_CXX_LIBRARY": "libc++",
        "MACOSX_DEPLOYMENT_TARGET": "11.6"
      },
      "msvs_settings": {
        "VCCLCompilerTool": { "ExceptionHandling": 1 },
      }
    }
  ]
}