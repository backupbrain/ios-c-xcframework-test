# Creating a C module for iOS

This project is a way to test compiling static C modules for iOS Simulator and Device

## Compiling

```bash
# Point the  sysdir to iOS SDK
export SDKROOT=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk

# create the working folder
mkdir lib

# Copy the header file
cp src/vectors.h lib/vectors.h

# Compile the object file
gcc -c -o lib/vectors-arm64.a -arch arm64 src/vectors.c -target arm64-apple-ios -fembed-bitcode
gcc -c -o lib/vectors-x86_64.a -arch x86_64 src/vectors.c -target x86_64-apple-ios-simulator

# Create an xcframework
xcrun xcodebuild -create-xcframework \
    -library ./lib/vectors-arm64.a \
    -headers ./lib/vectors.h \
    -library ./lib/vectors-x86_64.a \
    -headers ./lib/vectors.h \
    -output ./lib/vectors.xcframework
# Copy the header file

# Cleanup
rm lib/vectors-arm64.a lib/vectors-x86_64.a
```

# Usage

## Install into iOS Project
Drag and drop the `vectors.xcframework` and `vectors.h` into an iOS App XCode project.

Create a `<Project-Name>-Bridging-Header.h` and add the following line inside the `#ifndef / #endif`:

```obj-c
#import "vectors.h"
```

## Use methods in code:

You can use the `vectors` methods somewhere in your Swift code like this:

```swift
let a: [Int32] = [1, 2]
let b: [Int32] = [4, 5]
var result: [Int32] = [0, 0]

add_vector(&a, &b, &result, 2)
print("\(a) + \(b) = \(result)")

multiply_vector(&a, &b, &result, 2)
print("\(a) * \(b) = \(result)")
```

The resulting output in the debugger will look like this when running the app:

```
[1, 2] + [4, 5] = [5, 7]
[1, 2] * [4, 5] = [4, 10]
```

## More information

* [Guide to including a C library into an iOS project written in Swift](https://rlaguilar.com/posts/integrate-c-library-ios-project-swift/)

There is a deprecated way to create universal binaries:

```bash
# Create universal object files - deprecated way to create universal binaries
lipo -create lib/vectors-arm64.a lib/vectors-x86_64.a -output lib/vectors.o
# create a static library from the object file
libtool -static lib/vectors-arm64.o lib/vectors-x86_64.o -o lib/libvectors-macOS.a
libtool -static lib/vectors-x86_64.o -o lib/libvectors-x86_64.a -arch x86_64

# Create a universal static binary
libtool -static lib/vectors.o -o lib/libvectors.a
```