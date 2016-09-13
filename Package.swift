import PackageDescription

let package = Package(
    name: "OnigGlue",
    dependencies: [
        .Package(url: "https://github.com/baberthal/COniguruma.git", majorVersion: 0)
    ]
)
