// swift-tools-version:5.9
// Swift Package Manager distribution of the Jibestream OutdoorIndoorKit, starting at 2.0.0.
// The same git tag also serves the CocoaPods podspec (OutdoorIndoorKit-iOS-Pod.podspec) until
// CocoaPods is retired.
//
// Release: tag the commit with the bare semantic version (e.g. `2.0.0`, no `v` prefix) and keep
// `s.version` in OutdoorIndoorKit-iOS-Pod.podspec in step with it.
import PackageDescription

let package = Package(
    name: "OutdoorIndoorKit-iOS-Pod",
    platforms: [
        // iOS 15 matches the rest of the Jibestream SDK stack, and it is also the floor of the
        // GoogleMaps 9.x line this package pins. GoogleMaps 10.x requires iOS 16 and 11.x
        // requires iOS 17, so moving to either means raising this floor in step.
        .iOS(.v15)
    ],
    products: [
        // OutdoorIndoorKitSPMSupport ships in the same product as the binary target on purpose:
        // see its comment below. A consumer adds this one product and gets both.
        .library(
            name: "JMapOutdoorIndoorKit",
            targets: ["JMapOutdoorIndoorKit", "OutdoorIndoorKitSPMSupport"]
        )
    ],
    dependencies: [
        // A range, not `exact:`. An exact pin here makes the dependency graph
        // unsatisfiable for any consumer that declares its own JMapiOSSDK requirement.
        .package(url: "https://github.com/Jibestream/JMap-iOS-SDK-Pod.git", from: "6.0.0"),
        // GoogleMaps is not optional. JMapGMController.h and JMapGMGeometry.h
        // `#import <GoogleMaps/GoogleMaps.h>` and expose GMSMapView, GMSMapViewDelegate,
        // GMSOverlay and GMSPolyline in their public API, so it is needed to compile; and the
        // archive leaves GMSMapView, GMSMarker, GMSPolyline, GMSPolygon, GMSPath,
        // GMSMutablePath, GMSOverlay, GMSGroundOverlay, GMSCameraUpdate and GMSCoordinateBounds
        // undefined, so it is needed to link. Unlike this archive's other dependencies it is
        // NOT auto-linked: there is no LC_LINKER_OPTION entry for it.
        //
        // The CocoaPods podspec never declared this, so CocoaPods consumers have always had to
        // add GoogleMaps to their own Podfile. Both manifests declare it as of 2.0.0.
        //
        // Pinned to the 9.x line deliberately: 9.x is the last GoogleMaps line with an iOS 15
        // floor. Widening the range would let SwiftPM resolve 10.x or 11.x, which declare iOS 16
        // and iOS 17 and would fail to resolve for an iOS 15 consumer.
        .package(url: "https://github.com/googlemaps/ios-maps-sdk.git", from: "9.0.0")
    ],
    targets: [
        // Static Objective-C framework containing no Objective-C categories of its own, so it
        // adds no -ObjC requirement beyond the one JMapiOSSDK already imposes.
        //
        // The archive carries LC_LINKER_OPTION entries covering its system frameworks (Metal,
        // OpenGLES, GLKit, CoreLocation, ...) as well as JMapCoreKit, JMapRenderingKit and
        // WebKit, so those auto-link. GoogleMaps is the one exception and is carried by the
        // support target below. Hence no linkerSettings here.
        .binaryTarget(
            name: "JMapOutdoorIndoorKit",
            path: "OutdoorIndoorKit-iOS-Pod/Frameworks/JMapOutdoorIndoorKit.xcframework"
        ),
        // Exists only to carry the dependency edges, which `.binaryTarget` cannot declare.
        // JMapOutdoorIndoorKit's public headers `#import <JMapCoreKit/JMapCoreKit.h>`,
        // `<JMapRenderingKit/...>` and `<GoogleMaps/GoogleMaps.h>`, so without these edges
        // `import JMapOutdoorIndoorKit` fails to compile with a "file not found" error.
        .target(
            name: "OutdoorIndoorKitSPMSupport",
            dependencies: [
                .product(name: "JMapiOSSDK", package: "JMap-iOS-SDK-Pod"),
                .product(name: "GoogleMaps", package: "ios-maps-sdk")
            ]
        )
    ]
)
