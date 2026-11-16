// Intentionally empty.
//
// This target carries OutdoorIndoorKit-iOS-Pod's dependencies on JMapiOSSDK and GoogleMaps.
// SPM's `.binaryTarget` accepts no `dependencies:`, and JMapOutdoorIndoorKit's public headers
// `#import` both the JMapiOSSDK umbrella headers and <GoogleMaps/GoogleMaps.h>, so the edges
// have to live on a regular target that ships in the same product. SwiftPM rejects a target
// with no sources, hence this file.
//
// Do not add API here. JMapOutdoorIndoorKit is what consumers import.
