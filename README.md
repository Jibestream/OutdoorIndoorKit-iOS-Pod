# OutdoorIndoorKit-iOS-Pod

[![CI Status](https://img.shields.io/travis/louieyuen/OutdoorIndoorKit-iOS-Pod.svg?style=flat)](https://travis-ci.org/louieyuen/OutdoorIndoorKit-iOS-Pod)
[![Version](https://img.shields.io/cocoapods/v/OutdoorIndoorKit-iOS-Pod.svg?style=flat)](https://cocoapods.org/pods/OutdoorIndoorKit-iOS-Pod)
[![License](https://img.shields.io/cocoapods/l/OutdoorIndoorKit-iOS-Pod.svg?style=flat)](https://cocoapods.org/pods/OutdoorIndoorKit-iOS-Pod)
[![Platform](https://img.shields.io/cocoapods/p/OutdoorIndoorKit-iOS-Pod.svg?style=flat)](https://cocoapods.org/pods/OutdoorIndoorKit-iOS-Pod)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

- **iOS 15.0 or later**, as of 2.0.0. Release 1.2.0 and earlier declare a lower
  floor (the podspec carried conflicting iOS 9.0 and 10.0 declarations) and
  remain resolvable, so a project that cannot move to iOS 15 yet can stay
  pinned to 1.2.0.
- **Xcode 15 or later** for Swift Package Manager (`Package.swift` declares
  `swift-tools-version:5.9`). CocoaPods has no additional Xcode requirement
  beyond what the binary itself needs.
- **[JMapiOSSDK](https://github.com/Jibestream/JMap-iOS-SDK-Pod) 6.0.0 or later.**
  `JMapOutdoorIndoorKit`'s public headers `#import <JMapCoreKit/JMapCoreKit.h>`
  and `<JMapRenderingKit/...>`, so the SDK is a compile-time requirement and not
  merely a link-time one. Both manifests declare it, so either package manager
  resolves it for you. Releases 1.2.0 and earlier did not declare this
  dependency at all, and had to be paired with JMapiOSSDK by hand.
- **[GoogleMaps](https://github.com/googlemaps/ios-maps-sdk) 9.x.** This kit is
  a Google Maps integration: `JMapGMController` and `JMapGMGeometry`
  `#import <GoogleMaps/GoogleMaps.h>` and expose `GMSMapView`,
  `GMSMapViewDelegate`, `GMSOverlay` and `GMSPolyline` directly in their public
  API, and the binary leaves the GMS classes it uses undefined for your app to
  link. Releases 1.2.0 and earlier did not declare this either, so CocoaPods
  users had to add GoogleMaps to their own Podfile.

  **The 9.x ceiling is deliberate.** GoogleMaps 9.x is the last line with an
  iOS 15 floor; 10.x requires iOS 16 and 11.x requires iOS 17. Widening the
  range would let the resolver pick a version that cannot satisfy this
  package's own iOS 15 floor. If you need GoogleMaps 10 or 11, that has to come
  with a matching bump to this package's deployment target.

  You also need a Google Maps API key: `JMapGMController` and
  `JMapGMMultiVenueController` take one in their initializers.
- **`-ObjC` in your target's Other Linker Flags.** `JMapOutdoorIndoorKit` itself contains no
  Objective-C categories and needs no linker flags of its own, but the
  JMapiOSSDK frameworks underneath it do: without `-ObjC` their categories are
  not registered at runtime, producing an `unrecognized selector` crash during
  map parsing. The build succeeds either way, so the failure is silent until
  run time. CocoaPods writes this flag into its generated xcconfig
  automatically; with Swift Package Manager you must set it yourself.

## Installation

OutdoorIndoorKit supports **both** Swift Package Manager and CocoaPods. Both are served
from this one repository and the same git tag: SPM reads `Package.swift`,
CocoaPods reads `OutdoorIndoorKit-iOS-Pod.podspec`, and both point at the same
XCFramework under `OutdoorIndoorKit-iOS-Pod/Frameworks/`. Each ignores the other's
manifest.

> **Pick one.** Adding OutdoorIndoorKit through both CocoaPods and Swift Package Manager in
> the same project links the framework twice and fails with duplicate symbol
> errors. The same applies to `JMapiOSSDK` and `GoogleMaps` underneath it: all
> must come from the same package manager.

### Swift Package Manager (2.0.0 and later)

In Xcode, choose **File > Add Package Dependencies...**, enter
`https://github.com/Jibestream/OutdoorIndoorKit-iOS-Pod.git`, pick **Up to Next Major Version**
from `2.0.0`, and add the `JMapOutdoorIndoorKit` product to your app target.

Or, in a `Package.swift`:

```swift
dependencies: [
    .package(url: "https://github.com/Jibestream/OutdoorIndoorKit-iOS-Pod.git", from: "2.0.0")
],
targets: [
    .target(
        name: "YourTarget",
        dependencies: [.product(name: "JMapOutdoorIndoorKit", package: "OutdoorIndoorKit-iOS-Pod")]
    )
]
```

The product provides the `JMapOutdoorIndoorKit` module and brings in both
JMapiOSSDK (`JMapCoreKit`, `JMapRenderingKit`, `JMapControllerKit`) and
GoogleMaps transitively, so you do not add either package separately.

Swift Package Manager support is available from **2.0.0** onward. Earlier tags do
not contain a `Package.swift` and cannot be resolved by SPM.

### CocoaPods (deprecated)

CocoaPods support continues for now but will be removed in a future release;
please move to Swift Package Manager.

To install, simply add the following line to your Podfile:

```ruby
pod 'OutdoorIndoorKit-iOS-Pod', :git => 'https://github.com/Jibestream/OutdoorIndoorKit-iOS-Pod.git'
```

For installing the first time run:
```ruby
pod install
```

To get the latest version of the pod run:
```ruby
pod update
```

## Author

Louie, lyuen@jibestream.com
