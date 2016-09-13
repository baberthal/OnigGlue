import PackageDescription

let package = Package(
    name: "OnigGlue",
    dependencies: [
        .Package(url: "../COniguruma", majorVersion: 0)
    ]
)
